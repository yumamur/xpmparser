#include "xpmft_int.h"

static t_ulong inline	file_get_size(t_c_char *file_name)
{
	DEBUG_FUNC();
	int		fd;
	char	buf[50];
	t_ulong	rd_byte;
	t_ulong	ret;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = 0;
	while (1)
	{
		rd_byte = read(fd, buf, 50);
		if (rd_byte > 0)
			ret += rd_byte;
		else if (!rd_byte)
			break ;
		else
			return (-1);
	}
	close(fd);
	return (ret);
}

void	file_destroy(t_file *file)
{
	DEBUG_FUNC();
	free(file->addr);
	*file = (t_file){};
}

t_file	file_load(t_c_char *file_name)
{
	DEBUG_FUNC();
	int		fd;
	t_file	data;

	data.size = file_get_size(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ((t_file){});
	data.addr = malloc(data.size + 1);
	if (data.addr && read(fd, data.addr, data.size) > 0)
	{
		close(fd);
		((char *)data.addr)[data.size] = 0;
		return (data);
	}
	close(fd);
	free(data.addr);
	return ((t_file){});
}
