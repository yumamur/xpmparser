#ifndef XPMFT_INT_H
# define XPMFT_INT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/mman.h>
# include "typeft.h"

typedef struct s_colour
{
	char	*key;
	char	*val;
}	t_colour;

typedef struct s_xpm
{
	t_uint		width;
	t_uint		height;
	t_uint		cn;
	t_uint		cpp;
	t_colour	*clr;
	t_uint		**data;
}	t_xpm;

typedef struct s_mmap
{
	void	*addr;
	t_ulong	size;
}	t_mmap;

void		*ft_2d_malloc(t_ulong col, t_ulong row, t_ulong size);

int			ft_pos_strstr_quote(char *str, char *to_find, t_ulong size);
int			ft_pos_strstr(char *str, char *to_find, t_ulong size);
char		**ft_str_wordtab(char *str);

int			xpmparse_remove_comment(const t_mmap *data);

char		*xpmparse_get_row(const t_mmap *data);
t_colour	xpmparse_colour_row(char *row, t_ulong cpp);
void		xpmparse_pixel_row(char *row, t_xpm *xpm, t_ulong row_nbr);
#endif
