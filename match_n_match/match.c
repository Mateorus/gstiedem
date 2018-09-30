#include <stdio.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		str++;
		counter++;
	}
	return (counter);
}

char	*ft_strcmp(char *s1, char *s2)
{
	char	*start;
	int	flag;

	flag = 0;
	start = s2;
	while (*s1)
	{
		if (((*s1 == *s2) && *s2 != '*' && *s1))
		{
			s2++;
			flag = 1;
		}
		else if (*s2 == '*' || *s2 == 0)
			return (s1);
		else if (flag)
		{
			s2 = start;
			s1--;
		}
		s1++;
	}
	if (!(*s1 - *s2))
		return (s1);
	else
		return (0);
}

int	match(char *s1, char *s2)
{
	char	*p;;

	while (*s1)
	{
		if (*s1 == *s2)
			s2++;
		else if (*s2 == '*')
		{
			s2++;
			p = ft_strcmp(s1, s2);
			if (p)
			{
				s1 = p;
				continue;
			}
			else
				return (0);
		}
		else
			return (0);
		s1++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%i", match(argv[1], argv[2]));
	return (0);
}

