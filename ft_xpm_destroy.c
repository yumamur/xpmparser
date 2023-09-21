#include "xpmft_int.h"

void	ft_xpm_destroy(t_xpm *img)
{
	t_uint	i;

	if (img)
	{
		i = 0;
		while (i < img->cn)
		{
			free(img->clr.chars[i]);
			free(img->clr.s_keys[i].c);
			free(img->clr.s_keys[i].s);
			free(img->clr.s_keys[i].m);
			free(img->clr.s_keys[i].g);
			++i;
		}
		free(img->clr.chars);
		free(img->clr.s_keys);
		free(img->data);
		free(img);
	}
}
