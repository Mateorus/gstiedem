#include <stdlib.h>
int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
	|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_wordlen(char *str)
{
	int	len;

	len = 0;
	while (!ft_isspace(*str) && *str)
	{
		len++;
		str++;
	}
	return (len);

}

int	ft_count_words(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (!ft_isspace(*str) && (ft_isspace(*(str + 1)) || *(str + 1) == 0))
			num++;
		str++;
	}
	return (num);
}

char	*ft_strlcpy(char *src, int len)
{
	char	*dest;
	char	*copy;

	copy = malloc(sizeof(*copy) * (len + 1));
	copy[len] = 0;
	dest = copy;
	while (len)
	{
		*dest++ = *src++;
		len--;
	}
	return (copy);
}

char	**ft_split_whitespaces(char *str)
{
	char	**p;
	int	num_w;
	int	i;

	num_w = ft_count_words(str);
	p = malloc(sizeof(*p) * (num_w + 1));
	p[num_w] = 0;
	i = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			p[i++] = ft_strlcpy(str, ft_wordlen(str));
			str += ft_wordlen(str) - 1;
		}
		str++;
	}
	return (p);
}
