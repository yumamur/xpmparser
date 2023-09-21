#include "xpmft_int.h"

void	ft_xpm_destroy(t_xpm *img)
{
	t_uint	i;

	if (img)
	{
		i = 0;
		while (i < img->cn)
		{
			free(img->clr.key[i]);
			free(img->clr.val[i]);
			++i;
		}
		free(img->clr.key);
		free(img->clr.val);
		free(img->data);
		free(img);
	}
}
