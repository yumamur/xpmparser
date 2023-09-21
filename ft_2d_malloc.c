#include <stdlib.h>
#include <string.h>
#include "typeft.h"

void	*ft_2d_malloc(t_ulong col, t_ulong row, t_ulong byte)
{
	void	**ret;
	t_ulong	i;

	ret = malloc(sizeof(void *) * (row + 1) + row * col * byte);
	if (!ret)
		return (ret);
	ret[0] = ret + row + 1;
	i = 0;
	while (++i < row)
		ret[i] = ret[i - 1] + col * byte;
	ret[i] = 0;
	return (ret);
}

void	*ft_2d_calloc(t_ulong col, t_ulong row, t_ulong byte)
{
	void	**ret;
	t_ulong	i;

	ret = malloc(sizeof(void *) * (row + 1) + row * col * byte);
	if (!ret)
		return (ret);
	ret = memset(ret, 0, sizeof(void *) * (row + 1) + row * col * byte);
	ret[0] = ret + row + 1;
	i = 0;
	while (++i < row)
		ret[i] = ret[i - 1] + col * byte;
	ret[i] = 0;
	return (ret);
}
