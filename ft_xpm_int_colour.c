#include "xpmft_int.h"

static char	*xpmparse_get_key_data(char **tab, const char key[])
{
	DEBUG_FUNC();
	t_uint	begin;
	t_uint	end;

	end = 0;
	while (tab[end])
	{
		if (*(t_uint16 *)tab[end] == *(t_uint16 *)key)
		{
			begin = end + 1;
			while (tab[++end]
				&& *(t_uint16 *)tab[end] == (t_uint16){'c' << 8}
				&& *(t_uint16 *)tab[end] == (t_uint16){'s' << 8}
				&& *(t_uint16 *)tab[end] == (t_uint16){'m' << 8}
				&& *(t_uint16 *)tab[end] == (t_uint16){'g' << 8})
				memmove(tab[begin] + strlen(tab[begin]), tab[end],
					strlen(tab[end]) + 1);
			return (strdup(tab[begin]));
		}
		++end;
	}
	return (NULL);
}

t_colourkeys	xpmparse_colour_keys(char *row)
{
	DEBUG_FUNC();
	char			**tab;
	t_colourkeys	ret;

	tab = ft_str_wordtab(row);
	if (!tab)
		return ((t_colourkeys){});
	ret.c = xpmparse_get_key_data(tab, "c");
	ret.s = xpmparse_get_key_data(tab, "s");
	ret.m = xpmparse_get_key_data(tab, "m");
	ret.g = xpmparse_get_key_data(tab, "g");
	free(tab);
	return (ret);
}

int	xpmparse_colour_row(char *row, t_colour *clr, t_uint index, t_ulong cpp)
{
	DEBUG_FUNC();
	if (cpp >= strlen(row) - 4)
		return (-1);
	clr->chars[index] = malloc(cpp + 1);
	if (clr->chars[index])
	{
		memcpy(clr->chars[index], row, cpp);
		clr->chars[index][cpp] = 0;
		row += cpp;
		clr->keys[index] = xpmparse_colour_keys(row);
		return (0);
	}
	return (-1);
}

int	xpmparse_find_colour(t_xpm *img, char *row)
{
	DEBUG_FUNC();
	t_uint	i;

	i = 0;
	while (i < img->cn)
	{
		if (!memcmp(row, img->clr.chars[i], img->cpp))
			return (i);
		++i;
	}
	return (-1);
}
