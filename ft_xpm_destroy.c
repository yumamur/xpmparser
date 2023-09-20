#include "xpmft_int.h"

void	ft_xpm_destroy(t_xpm *img)
{
	t_uint	i;

	if (img)
	{
		i = 0;
		while (i < img->cn)
		{
			free(img->clr[i].key);
			free(img->clr[i].val);
			++i;
		}
		free(img->clr);
		free(img->data);
		free(img);
	}
}
