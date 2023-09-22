#ifndef XPMFT_H
# define XPMFT_H

# include "typeft.h"

void		ft_xpm_put_imgdata(void *img);
void		*ft_xpm_convert(const char *file);
void		ft_xpm_destroy(void *img);
void		*ft_xpm_new(t_ulong width, t_ulong height);
#endif
