#include "xpmft_int.h"
#include <stdlib.h>

void	ft_xpm_destroy(t_xpm *img)
{
	t_uint	i;

	DEBUG_FUNC;
	if (img)
	{
		i = 0;
		while (i < img->cn)
		{
			free(img->clr[i].chars);
			free(img->clr[i].key_c);
			free(img->clr[i].key_s);
			free(img->clr[i].key_m);
			free(img->clr[i].key_g);
			free(img->clr[i].key_g4);
			img->clr[i] = (t_colour){};
			++i;
		}
		if (img->clr)
			free(img->clr);
		if (img->data)
			free(img->data);
		*img = (t_xpm){};
		free(img);
	}
}
