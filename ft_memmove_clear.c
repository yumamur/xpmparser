#include "typeft.h"

void	memmove_clear(void *dst, void *src, t_uint64 size)
{
	if (dst < src)
	{
		while (size--)
		{
			*(t_uchar *)dst++ = *(t_uchar *)src;
			*(t_uchar *)src++ = 0;
		}
	}
	else if (dst > src)
	{
		while (size--)
		{
			((t_uchar *)dst)[size] = ((t_uchar *)src)[size];
			((t_uchar *)src)[size] = 0;
		}
	}
}
