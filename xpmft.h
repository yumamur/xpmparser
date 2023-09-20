#ifndef XPMFT_H
# define XPMFT_H

# include "typeft.h"

void		print_imgdata(void *img);
void		*ft_xpm_convert(const char *file);
void		ft_xpm_destroy(void *img);
#endif
