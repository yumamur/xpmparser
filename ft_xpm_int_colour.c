#include "xpmft_int.h"

t_colourkeys	xpmparse_colour_keys(char *row);

int	xpmparse_colour_row(char *row, t_colour *clr, t_uint index, t_ulong cpp)
{
	t_ulong		len;

	if (cpp >= strlen(row) - 6)
		return (-1);
	clr->chars[index] = malloc(cpp + 1);
	if (*clr->chars)
	{
		memcpy(*clr->chars, row, cpp);
		clr->chars[index][cpp] = 0;
		row += cpp;
		clr->keys[index] = xpmparse_colour_keys(row);
	}
	return (-1);
}

int	xpmparse_find_colour(t_xpm *img, char *row)
{
	t_uint	i;

	i = 0;
	while (i < img->cn)
	{
		if (!memcmp(row, img->clr.chars[i], img->cpp))
			return (i);
		++i;
	}
	return (-1);
}
