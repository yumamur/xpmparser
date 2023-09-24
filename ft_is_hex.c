int	is_hex(char str[])
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9')
			|| (*str >= 'a' && *str <= 'f')
			|| (*str >= 'A' && *str <= 'F'))
			++str;
		if (!*str)
			return (0);
	}
	return (-1);
}
