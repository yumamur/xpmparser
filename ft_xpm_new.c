#include "xpmft_int.h"
#include <stdlib.h>

void	*ft_xpm_new(t_ulong width, t_ulong height)
{
	t_xpm	*ret;

	DEBUG_FUNC;
	ret = malloc(sizeof(t_xpm));
	if (ret)
	{
		*ret = (t_xpm){};
		ret->width = width;
		ret->height = height;
		ret->data = ft_2d_calloc(ret->width, ret->height, sizeof(int));
		if (!ret->data)
		{
			*ret = (t_xpm){};
			return (NULL);
		}
	}
	return (ret);
}
