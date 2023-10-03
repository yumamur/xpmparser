#include "xpmft_int.h"

void	ft_xpm_add_image(t_xpm *base, t_xpm *add, t_uint pos_w, t_uint pos_h)
{
	t_colour	*tmp;

	if (!base || !add || pos_w > base->width || pos_h > base->height)
		return ;
	tmp = ft_xpm_int_congregate_colours(2, base->clr, add->clr);
}
