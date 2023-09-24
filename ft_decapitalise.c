#include "xpmft_int.h"

void	decapitalise(char *str)
{
	unsigned int	i;

	DEBUG_FUNC;
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return ;
}
