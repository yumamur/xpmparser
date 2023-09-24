#include "xpmft_int.h"
#include <stdio.h>

static void	xpm_put_values(t_xpm *img)
{
	printf("width\theight\tcnumber\tcpp\n%d\t%d\t%d\t%d\n",
		img->width, img->height, img->cn, img->cpp);
}

static void	xpm_put_colours(t_xpm *img)
{
	t_uint	i;

	i = 0;
	while (i < img->cn)
	{
		printf("colour\t%u\tc  <%s>\n\t\tm  <%s>\nchars\t"
			"\tg  <%s>\n%s\t\tg4 <%s>\n\t\ts  <%s>\n", i,
			img->clr[i].key_c, img->clr[i].key_m, img->clr[i].key_g,
			img->clr[i].chars, img->clr[i].key_g4, img->clr[i].key_s);
		if (++i < img->cn)
			printf("---------------------------\n");
	}
}

void	ft_xpm_put_imgdata(t_xpm *img)
{
	t_uint	i;
	t_uint	j;

	DEBUG_FUNC;
	printf("########################################\n");
	xpm_put_values(img);
	printf("===================================\n");
	xpm_put_colours(img);
	printf("===================================\n");
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
			printf("%x ", img->data[i][j++]);
		printf("\n");
		++i;
	}
	printf("########################################\n");
}
