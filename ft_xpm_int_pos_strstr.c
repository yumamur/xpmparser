#include "xpmft_int.h"

int	ft_pos_strstr(char *str, char *to_find, t_ulong size)
{
	t_ulong	pos;
	t_ulong	ctl;

	if (strlen(to_find) > size)
		return (-1);
	pos = 0;
	while (str[pos] && pos < size)
	{
		ctl = 0;
		while (str[pos + ctl] == to_find[ctl])
		{
			++ctl;
			if (!to_find[ctl])
				return (pos);
		}
		++pos;
	}
	return (-1);
}

int	ft_pos_strstr_quote(char *str, char *to_find, t_ulong size)
{
	t_ulong	var[3];

	if (strlen(to_find) > size)
		return (-1);
	var[0] = 0;
	var[1] = 0;
	while (str[var[0]] && var[0] < size)
	{
		if (str[var[0]] == '\"')
			var[1] = 1 - var[1];
		if (!var[1])
		{
			var[2] = 0;
			while (str[var[0] + var[2]] == to_find[var[2]])
			{
				++var[2];
				if (!to_find[var[2]])
					return (var[0]);
			}
		}
		++var[0];
	}
	return (-1);
}
