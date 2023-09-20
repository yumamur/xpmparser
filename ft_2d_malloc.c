#include <stdlib.h>
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
