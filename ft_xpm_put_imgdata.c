#include "xpmft_int.h"
#include <stdio.h>

void	ft_xpm_put_imgdata(t_xpm *img)
{
	DEBUG_FUNC();
	t_uint	i;
	t_uint	j;

	printf("########################################\n");
	printf("width\t%d\nheight\t%d\ncnumber\t%d\ncpp\t%d\n",
		img->width, img->height, img->cn, img->cpp);
	i = 0;
	printf("===================================\n");
	while (i < img->cn)
	{
		printf("colour\t%u\tchars %s\n\t\tc_key %s\n\t\tm_key %s\n"
			"\t\ts_key %s\n\t\tg_key %s\n", i, img->clr.chars[i],
		 	img->clr.keys[i].c, img->clr.keys[i].m, img->clr.keys[i].s,
		 	img->clr.keys[i].g);
		++i;
		if (i < img->cn)
			printf("---------------------------\n");
	}
	i = 0;
	printf("===================================\n");
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
	printf("########################################\n");
}
