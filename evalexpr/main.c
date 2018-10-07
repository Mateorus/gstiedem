#include <stdio.h>
char	**ft_split_whitespaces(char *str);

int	ft_atoi(char *str);

int	calculus(char *a, char *b, char sign)
{
	if (sign == '*')
		return (ft_atoi(a) * ft_atoi(b));
	else if (sign == '/')
		return (ft_atoi(a) / ft_atoi(b));
	else if (sign == '%')
		return (ft_atoi(a) % ft_atoi(b));
	else if (sign == '-')
		return (ft_atoi(a) - ft_atoi(b));
	else if (sign == '+')
		return (ft_atoi(a) + ft_atoi(b));
	return (0);
}

int	eval_expr(char *str)
{
	char	**av;
	int	sum;
	int	sub_sum;
	int	i;

	av = ft_split_whitespaces(str);
	sum = 0;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '*' || av[i][0] == '/' || av[i][0] == '%')
		{
			if (av[i - 2][0] == '-')
				sum += -(calculus(av[i - 1], av[i + 1], av[i][0]));
			sum += calculus(av[i - 1], av[i + 1], av[i][0]);
		}
		else
			sum += calculus(av[i - 1], av[i + 1], av[i][0]);
		i + 2;
	}
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '+')
			sum += ft_atoi(av[i - 1]);
		i++;
	}
	return (sum);
}

int main(int ac, char **av)
{
	if (ac > 1)
		printf("%i\n", eval_expr(av[1]));
	return (0);
}
