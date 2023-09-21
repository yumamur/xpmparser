#include "xpmft_int.h"

void	*ft_xpm_new(t_ulong width, t_ulong height)
{
	t_xpm	*ret;

	ret = malloc(sizeof(t_xpm));
	if (ret)
	{
		*ret = (t_xpm){};
		ret->width = width;
		ret->height = height;
		ret->data = ft_2d_calloc(ret->width, ret->height, sizeof(int));
	}
	return (ret);
}
