void	decapitalise(char *str)
{
	unsigned int	i;

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
