// #include <stdlib.h>
#include "xpmft_int.h"

static int	count_words(char *str)
{
	DEBUG_FUNC();
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str == '\t' || *str == ' ')
			++str;
		if (*str)
			++ret;
		while (*str && *str != '\t' && *str != ' ')
			++str;
	}
	return (ret);
}

char	**ft_str_wordtab(char *str)
{
	DEBUG_FUNC();
	char	**ret;
	int		ct_word;

	ct_word = count_words(str);
	ret = malloc(++ct_word * sizeof(char *));
	if (!ret)
		return (0);
	ct_word = 0;
	while (*str)
	{
		while (*str == '\t' || *str == ' ')
			*str++ = 0;
		if (*str)
			ret[ct_word++] = str;
		while (*str && *str != '\t' && *str != ' ')
			++str;
	}
	ret[ct_word] = 0;
	return (ret);
}
