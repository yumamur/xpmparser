#ifndef XPMFT_INT_H
# define XPMFT_INT_H

# include "typeft.h"
# include "endianft.h"

# ifndef DEBUG
#  define DEBUG_FUNC ;
# endif

typedef struct s_colour
{
	char	*chars;
	char	*key_c;
	char	*key_m;
	char	*key_g;
	char	*key_g4;
	char	*key_s;
	t_uint	argb;
}	t_colour;

typedef struct s_xpm
{
	char		*name;
	t_uint		width;
	t_uint		height;
	t_uint		cn;
	t_uint		cpp;
	t_colour	*clr;
	t_uint		**data;
}	t_xpm;

typedef struct s_file
{
	void	*addr;
	t_ulong	size;
}	t_file;

int			is_hex(char str[]);
void		*ft_2d_malloc(t_ulong col, t_ulong row, t_ulong size);
void		*ft_2d_calloc(t_ulong col, t_ulong row, t_ulong size);
void		memmove_clear(void *dst, void *src, t_ulong size);
void		decapitalise(char *str);

int			ft_pos_strstr_quote(char *str, char *to_find, t_ulong size);
int			ft_pos_strstr(char *str, char *to_find, t_ulong size);
char		**ft_str_wordtab(char *str);

t_file		file_load(t_c_char *file_name);
void		file_destroy(t_file *file);

int			xpm_fileparse_remove_comment(const t_file *data);
char		*xpm_fileparse_get_row(const t_file *data);
int			xpm_fileparse_values(const t_file *data, t_xpm *img);
int			xpm_fileparse_colours(const t_file *data, t_xpm *img);
int			xpm_fileparse_pixels(const t_file *data, t_xpm *img);

t_uint		xpmparse_hash_argb_to_int(char hexstr[]);
int			xpmparse_colour_row(char *row, t_colour *clr, t_ulong cpp);
t_uint		xpmparse_find_colour(t_xpm *img, char *row);
void		xpmparse_pixel_row(char *row, t_xpm *xpm, t_ulong row_nbr);
#endif
