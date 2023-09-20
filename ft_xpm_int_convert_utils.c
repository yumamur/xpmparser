#include "xpmft_int.h"

int	xpmparse_remove_comment(const t_mmap *data)
{
	int	com_begin;
	int	com_len;

	while (1)
	{
		com_begin = ft_pos_strstr_quote(data->addr, "/*", data->size);
		if (com_begin == -1)
			break ;
		com_len = ft_pos_strstr_quote(data->addr + com_begin + 2,
				"*/", data->size);
		if (com_len == -1)
			return (-1);
		memmove(data->addr + com_begin, data->addr + com_begin + com_len + 4,
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

char	*xpmparse_get_row(const t_mmap *data)
{
	char		*row;
	static void	*ptr;

	if (!(ptr >= data->addr && ptr <= data->addr + data->size))
		ptr = data->addr;
	row = ptr + ft_pos_strstr(ptr, "\"", data->size);
	*row++ = 0;
	ptr = row + ft_pos_strstr(row, "\"", data->size);
	if (ptr >= (void *)row)
		*(char *)ptr++ = 0;
	return (row);
}

t_colour	xpmparse_colour_row(char *row, unsigned long cpp)
{
	t_colour	ret;
	t_ulong		len;

	if (cpp >= strlen(row) - 6)
		return ((t_colour){});
	ret.key = malloc(cpp + 1);
	if (ret.key)
	{
		memcpy(ret.key, row, cpp);
		ret.key[cpp] = 0;
		row += cpp;
		while (*row && *row != 'c' && *row != 'm'
			&& *row != 's' && *row != 'g')
			++row;
		len = strlen(row);
		ret.val = malloc(len + 1);
		if (ret.val)
		{
			memcpy(ret.val, row, len);
			ret.val[len] = 0;
			return (ret);
		}
		free(ret.key);
	}
	return ((t_colour){});
}

static t_uint	xpmparse_find_colour(t_xpm *img, char *row)
{
	t_uint	i;

	i = 0;
	while (i < img->cn)
	{
		if (!memcmp(row, img->clr[i].key, img->cpp))
			return (i);
		++i;
	}
	return (i);
}

void	xpmparse_pixel_row(char *row, t_xpm *xpm, t_ulong row_nbr)
{
	t_ulong	i;

	i = 0;
	while (i < xpm->width && strlen(row) >= xpm->cpp)
	{
		xpm->data[row_nbr][i] = xpmparse_find_colour(xpm, row);
		++i;
		row += xpm->cpp;
	}
	while (i < xpm->width)
		xpm->data[row_nbr][i] = 0;
}
