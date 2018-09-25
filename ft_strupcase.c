#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char *p;
	
	p = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
		str++;
	}
	return (p);
}

int main(void)
{
	char str[] = "aJSBYyhDsc  zxcvbnma  ";
	printf("%s\n", ft_strupcase(str));
}
