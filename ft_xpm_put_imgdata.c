#include <stdio.h>
#include "xpmft_int.h"

void	print_imgdata(t_xpm *img)
{
	t_uint	i;
	t_uint	j;

	printf("width\t%d\nheight\t%d\ncnumber\t%d\ncpp\t%d\n",
		img->width, img->height, img->cn, img->cpp);
	i = 0;
	while (i < img->cn)
	{
		printf("colour %u\tkey \"%s\"\tval \"%s\"\n",
			i, img->clr[i].key, img->clr[i].val);
		++i;
	}
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			printf("%d ", img->data[i][j]);
			++j;
		}
		++i;
		printf("\n");
	}
}