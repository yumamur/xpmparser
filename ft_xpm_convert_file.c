#include "xpmft_int.h"
#include <stdlib.h>

void	ft_xpm_destroy(void *xpm);

void	*ft_xpm_convert(const char *file_name)
{
	t_xpm	*img;
	t_file	data;

	DEBUG_FUNC;
	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	*img = (t_xpm){};
	leakproof_export(img, ft_xpm_destroy);
	data = file_load(file_name);
	if (!data.addr || !data.size)
		return (NULL);
	if (xpm_fileparse_remove_comment(&data))
		return (NULL);
	if (xpm_fileparse_values(&data, img))
		return (NULL);
	if (xpm_fileparse_colours(&data, img))
		return (NULL);
	if (xpm_fileparse_pixels(&data, img))
		return (NULL);
	file_destroy(&data);
	return (img);
}
