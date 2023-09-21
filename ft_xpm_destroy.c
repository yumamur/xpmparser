#include "xpmft_int.h"

void	ft_xpm_destroy(t_xpm *img)
{
	DEBUG_FUNC();
	t_uint	i;

	if (img)
	{
		i = 0;
		while (i < img->cn)
		{
			free(img->clr.chars[i]);
			free(img->clr.keys[i].c);
			free(img->clr.keys[i].s);
			free(img->clr.keys[i].m);
			free(img->clr.keys[i].g);
			++i;
		}
		free(img->clr.chars);
		free(img->clr.keys);
		free(img->data);
		free(img);
	}
}
