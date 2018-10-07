int	ft_isspace(char c);

int	ft_atoi(char *str)
{
	int	num;
	int	flag;
	
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		flag = 1;
		str++;
	}
	else
		flag = 0;
	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (flag)
		num = -num;
	return (num);
}
