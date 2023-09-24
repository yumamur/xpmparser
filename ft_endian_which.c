#include "endian.h"
#include "typeft.h"

enum e_endian {LITTLE, BIG}	which_endian(void)
{
	union
	{
		t_uint8		var2[2];
		t_uint16	var1;
	}	u_endian;

	u_endian.var1 = 1;
	if (u_endian.var1 == u_endian.var2[0])
		return (LITTLE);
	else
		return (BIG);
}
