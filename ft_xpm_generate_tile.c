#include "xpmft_int.h"
#include <stdlib.h>

void	*ft_xpm_new(t_ulong width, t_ulong height);
void	*ft_xpm_add_image(t_xpm *base, t_xpm *add, t_uint pos_w, t_uint pos_h);

void	*ft_xpm_generate_tile(t_xpm *img, t_uint width, t_uint height)
{
	t_xpm	*ret;
	t_uint	pos_w;
	t_uint	pos_h;

	if (!img || !width || !height)
		return (NULL);
	ret = ft_xpm_new(width, height);
	if (!ret)
		return (NULL);
	while (pos_h < height)
	{
		pos_w = 0;
		while (pos_w < width)
		{
			ft_xpm_add_image(ret, img, pos_w, pos_h);
			pos_w += img->width;
		}
		pos_h += img->height;
	}
	return (NULL);
}
