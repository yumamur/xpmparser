#include "xpmft_int.h"

int	xpmparse_remove_comment(const t_file *data)
{
	int	com_begin;
	int	com_len;

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

char	*xpmparse_get_row(const t_file *data)
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

void	xpmparse_pixel_row(char *row, t_xpm *xpm, t_ulong row_nbr)
{
	t_ulong	i;
	t_ulong	len;

	i = 0;
	len = strlen(row);
	while (i < xpm->width && len >= xpm->cpp)
	{
		xpm->data[row_nbr][i] = xpmparse_find_colour(xpm, row);
		++i;
		row += xpm->cpp;
		len -= xpm->cpp;
	}
	while (i < xpm->width)
		xpm->data[row_nbr][i] = -1;
}
