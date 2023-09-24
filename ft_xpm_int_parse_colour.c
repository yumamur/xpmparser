#include "typeft.h"
#include "xpmft_int.h"
#include <string.h>
#include <stdlib.h>

#define ARGB_NONE 0x00000000
#define HEX_VALS "0123456789abcdef"

t_uint	xpmparse_hash_argb_to_int(char hexstr[])
{
	t_uint	len;
	t_uint	ret;

	len = strlen(hexstr) - 1;
	decapitalise(hexstr);
	if ((len != 6 && len != 8) || *hexstr++ != '#' || is_hex(hexstr))
		return (ARGB_NONE);
	ret = ARGB_NONE;
	if (len == 8)
	{
		ret += (ft_pos_strstr(HEX_VALS, (char []){hexstr[0], 0}, 16) * 16
				+ ft_pos_strstr(HEX_VALS, (char []){hexstr[1], 0}, 16)) << 24;
		hexstr += 2;
	}
	ret += (ft_pos_strstr(HEX_VALS, (char []){hexstr[0], 0}, 16) * 16
			+ ft_pos_strstr(HEX_VALS, (char []){hexstr[1], 0}, 16)) << 16;
	ret += (ft_pos_strstr(HEX_VALS, (char []){hexstr[2], 0}, 16) * 16
			+ ft_pos_strstr(HEX_VALS, (char []){hexstr[3], 0}, 16)) << 8;
	ret += (ft_pos_strstr(HEX_VALS, (char []){hexstr[4], 0}, 16) * 16
			+ ft_pos_strstr(HEX_VALS, (char []){hexstr[5], 0}, 16)) << 0;
	return (ret);
}

static char	*xpmparse_get_key_value(char **tab, const char key[])
{
	t_uint	begin;
	t_uint	end;

	DEBUG_FUNC;
	end = 0;
	while (tab[end])
	{
		if (*(t_uint16 *)tab[end] == *(t_uint16 *)key)
		{
			begin = end + 1;
			while (tab[++end]
				&& *(t_uint16 *)tab[end] != *(t_uint16 *)"c"
				&& *(t_uint16 *)tab[end] != *(t_uint16 *)"m"
				&& *(t_uint16 *)tab[end] != *(t_uint16 *)"g"
				&& (*(t_uint16 *)tab[end] != *(t_uint16 *)"g4" && tab[end] + 2)
				&& *(t_uint16 *)tab[end] != *(t_uint16 *)"s")
			{
				if (begin != end)
					memmove_clear(tab[begin] + strlen(tab[begin]), tab[end],
						strlen(tab[end]));
			}
			return (strdup(tab[begin]));
		}
		++end;
	}
	return (strdup(""));
}

int	xpmparse_colour_row(char *row, t_colour *clr, t_ulong cpp)
{
	char	**tab;

	DEBUG_FUNC;
	clr->chars = malloc(cpp + 1);
	if (!clr->chars)
		return (-1);
	memcpy(clr->chars, row, cpp);
	clr->chars[cpp] = 0;
	row += cpp;
	tab = ft_str_wordtab(row);
	if (!tab)
		return (-1);
	clr->key_c = xpmparse_get_key_value(tab, "c");
	clr->key_m = xpmparse_get_key_value(tab, "m");
	clr->key_g = xpmparse_get_key_value(tab, "g");
	clr->key_g4 = xpmparse_get_key_value(tab, "g4");
	clr->key_s = xpmparse_get_key_value(tab, "s");
	free(tab);
	decapitalise(clr->key_c);
	decapitalise(clr->key_m);
	decapitalise(clr->key_g);
	decapitalise(clr->key_g4);
	decapitalise(clr->key_s);
	clr->argb = xpmparse_hash_argb_to_int(clr->key_c);
	return (0);
}

t_uint	xpmparse_find_colour(t_xpm *img, char *row)
{
	t_uint	i;

	DEBUG_FUNC;
	i = 0;
	while (i < img->cn)
	{
		if (!memcmp(row, img->clr[i].chars, img->cpp))
			return (img->clr[i].argb);
		++i;
	}
	return (ARGB_NONE);
}
