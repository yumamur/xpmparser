#include "xpmft_int.h"
#include <string.h>

void	xpmparse_pixel_row(char *row, t_xpm *img, t_ulong row_nbr)
{
	t_ulong	i;
	t_ulong	len;

	DEBUG_FUNC;
	i = 0;
	len = strlen(row);
	while (i < img->width && len >= img->cpp)
	{
		img->data[row_nbr][i] = xpmparse_find_colour(img, row);
		++i;
		row += img->cpp;
		len -= img->cpp;
	}
	while (i < img->width)
	{
		img->data[row_nbr][i] = 0x00000000;
		++i;
	}
}
