#include "xpmft.h"

int	main(int argc, char *argv[])
{
	void	*img1;
	void	*img2;
	void	*img3;

	if (argc < 2)
		return (0);
	img3 = ft_xpm_convert(argv[argc - 3]);
	print_imgdata(img3);
	img2 = ft_xpm_convert(argv[argc - 2]);
	print_imgdata(img2);
	img1 = ft_xpm_convert(argv[argc - 1]);
	print_imgdata(img1);
	ft_xpm_destroy(img3);
	ft_xpm_destroy(img2);
	ft_xpm_destroy(img1);
}
