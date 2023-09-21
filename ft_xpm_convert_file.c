#include "xpmft_int.h"

static int	parse_values(const t_file *data, t_xpm *img)
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

static int	parse_colours(const t_file *data, t_xpm *img)
{
	t_uint	clr_num;

	img->clr.chars = malloc(img->cn * sizeof(char *));
	if (!img->clr.chars)
		return (-1);
	img->clr.keys = malloc(img->cn * sizeof(*img->clr.keys));
	if (!img->clr.keys)
	{
		free(img->clr.chars);
		return (-1);
	}
	clr_num = 0;
	while (clr_num < img->cn)
	{
		if (xpmparse_colour_row(xpmparse_get_row(data),
				&img->clr, clr_num, img->cpp))
		{
			free(img->clr.chars);
			free(img->clr.keys);
			return (-1);
		}
		++clr_num;
	}
	return (0);
}

static int	parse_pixels(const t_file *data, t_xpm *img)
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

void	*ft_xpm_convert(const char *file_name)
{
	t_xpm	*img;
	t_file	data;

	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	data = file_load(file_name);
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
	file_destroy(&data);
	return (img);
}
