#include "xpmft_int.h"

static int	parse_values(const t_mmap *data, t_xpm *img)
{
	char	**tab;

	tab = ft_str_wordtab(xpmparse_get_row(data));
	img->width = atoi(tab[0]);
	img->height = atoi(tab[1]);
	img->cn = atoi(tab[2]);
	img->cpp = atoi(tab[3]);
	free(tab);
	if (img->width < 0 || img->height < 0 || img->cn < 0 || img->cpp < 0)
		return (-1);
	return (0);
}

static int	parse_colours(const t_mmap *data, t_xpm *img)
{
	t_uint	clr_num;

	img->clr = malloc(img->cn * sizeof(t_colour));
	if (!img->clr)
		return (-1);
	clr_num = 0;
	while (clr_num < img->cn)
	{
		img->clr[clr_num++] = xpmparse_colour_row(xpmparse_get_row(data),
				img->cpp);
	}
	return (0);
}

static int	parse_pixels(const t_mmap *data, t_xpm *img)
{
	t_ulong	row;

	img->data = ft_2d_malloc(img->width, img->height, 4);
	if (!img->data)
		return (-1);
	row = 0;
	while (row < img->height)
	{
		xpmparse_pixel_row(xpmparse_get_row(data), img, row);
		++row;
	}
	return (0);
}

t_mmap	load_file(const char *file_name)
{
	int		fd;
	t_mmap	data;

	fd = open(file_name, O_RDONLY);
	data.size = lseek(fd, 0, SEEK_END);
	data.addr = mmap(0, data.size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	return (data);
}

void	*ft_xpm_convert(const char *file_name)
{
	t_xpm	*img;
	t_mmap	data;

	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	data = load_file(file_name);
	if (!data.addr || !data.size)
		return (NULL);
	if (xpmparse_remove_comment(&data))
		return (NULL);
	if (parse_values(&data, img))
		return (NULL);
	if (parse_colours(&data, img))
		return (NULL);
	if (parse_pixels(&data, img))
		return (NULL);
	return (img);
}
