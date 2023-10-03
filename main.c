#include "xpmft.h"

int	main(int argc, char *argv[])
{
	void	*img;
	// int		i;

	if (argc < 2)
		return (0);
	// i = 1;
	// while (i < argc)
	// {
	// 	img = ft_xpm_convert(argv[i]);
	// 	ft_xpm_put_imgdata(img);
	// 	++i;
	// }
	img = ft_xpm_convert(argv[1]);
	ft_xpm_generate_tile(img, 6, 6);
}
