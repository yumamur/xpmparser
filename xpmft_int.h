#ifndef XPMFT_INT_H
# define XPMFT_INT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "typeft.h"

typedef struct s_colourkeys
{
	char	*c;
	char	*s;
	char	*m;
	char	*g;
}	t_colourkeys;

typedef struct s_colour
{
	char			**chars;
	t_colourkeys	*keys;
}	t_colour;

typedef struct s_xpm
{
	t_uint		width;
	t_uint		height;
	t_uint		cn;
	t_uint		cpp;
	t_colour	clr;
	t_uint		**data;
}	t_xpm;

typedef struct s_file
{
	void	*addr;
	t_ulong	size;
}	t_file;

t_file		file_load(const char *file_name);
void		file_destroy(t_file *file);
void		*ft_2d_malloc(t_ulong col, t_ulong row, t_ulong size);
void		*ft_2d_calloc(t_ulong col, t_ulong row, t_ulong size);

int			ft_pos_strstr_quote(char *str, char *to_find, t_ulong size);
int			ft_pos_strstr(char *str, char *to_find, t_ulong size);
char		**ft_str_wordtab(char *str);

int			xpmparse_remove_comment(const t_file *data);
char		*xpmparse_get_row(const t_file *data);

int			xpmparse_colour_row(char *row, t_colour *clr, t_uint index, t_ulong cpp);
int			xpmparse_find_colour(t_xpm *img, char *row);
void		xpmparse_pixel_row(char *row, t_xpm *xpm, t_ulong row_nbr);
#endif
