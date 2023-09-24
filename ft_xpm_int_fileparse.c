#include "xpmft_int.h"
#include <string.h>
#include <stdlib.h>

char	*xpm_fileparse_get_row(const t_file *data)
{
	char		*row;
	static void	*ptr;

	DEBUG_FUNC;
	if (!(ptr >= data->addr && ptr <= data->addr + data->size))
		ptr = data->addr;
	row = ptr + ft_pos_strstr(ptr, "\"", data->size);
	*row++ = 0;
	ptr = row + ft_pos_strstr(row, "\"", data->size);
	if (ptr >= (void *)row)
		*(char *)ptr++ = 0;
	return (row);
}

int	xpm_fileparse_remove_comment(const t_file *data)
{
	int	com_begin;
	int	com_len;

	DEBUG_FUNC;
	while (1)
	{
		com_begin = ft_pos_strstr_quote(data->addr, "/*", data->size);
		if (com_begin == -1)
			break ;
		com_len = ft_pos_strstr_quote(data->addr + com_begin + 2,
				"*/", data->size) + 4;
		if (com_len == -1)
			return (-1);
		memmove(data->addr + com_begin, data->addr + com_begin + com_len,
			data->size - com_begin - com_len);
		com_begin = ft_pos_strstr_quote(data->addr, "//", data->size);
		if (com_begin == -1)
			break ;
		com_len = ft_pos_strstr_quote(data->addr + com_begin, "\n", data->size);
		if (com_len == -1)
			return (-1);
		memmove(data->addr + com_begin, data->addr + com_begin + com_len,
			data->size - com_begin - com_len);
	}
	return (0);
}

int	xpm_fileparse_values(const t_file *data, t_xpm *img)
{
	char	**tab;

	DEBUG_FUNC;
	tab = ft_str_wordtab(xpm_fileparse_get_row(data));
	img->width = atoi(tab[0]);
	img->height = atoi(tab[1]);
	img->cn = atoi(tab[2]);
	img->cpp = atoi(tab[3]);
	free(tab);
	if (img->width < 0 || img->height < 0 || img->cn < 0 || img->cpp < 0)
		return (-1);
	return (0);
}

int	xpm_fileparse_colours(const t_file *data, t_xpm *img)
{
	t_uint	clr_num;

	DEBUG_FUNC;
	img->clr = malloc(img->cn * sizeof(t_colour));
	if (!img->clr)
	{
		img->cn = 0;
		return (-1);
	}
	clr_num = 0;
	while (clr_num < img->cn)
	{
		if (xpmparse_colour_row(xpm_fileparse_get_row(data),
				&img->clr[clr_num], img->cpp))
		{
			img->cn = clr_num;
			return (-1);
		}
		++clr_num;
	}
	return (0);
}

int	xpm_fileparse_pixels(const t_file *data, t_xpm *img)
{
	t_ulong	row;

	DEBUG_FUNC;
	img->data = ft_2d_malloc(img->width, img->height, 4);
	if (!img->data)
		return (-1);
	row = 0;
	while (row < img->height)
	{
		xpmparse_pixel_row(xpm_fileparse_get_row(data), img, row);
		++row;
	}
	return (0);
}
