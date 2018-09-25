#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char *p;
	
	p = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
	return (p);
}

int main(void)
{
	char str[] = "AAAJSBYyhDsc  ZxcvbnDFSma  ";
	printf("%s\n", ft_strlowcase(str));
}
