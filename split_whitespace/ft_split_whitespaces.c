/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:22:29 by gstiedem          #+#    #+#             */
/*   Updated: 2018/09/28 04:43:02 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			counter_words(char *str)
{
	int		num_words;
	
	num_words = 0;
	while (*str)
	{
		if (*str  == ' ' || *str == '\t' || *str == '\n')
			str++;
		else
		{
			while (*str++)
			{
				if ((*str  == ' ' || *str == '\t' || *str == '\n') || *str == '\0')
					break;
			}
			num_words++;
		}
	}
	return (num_words);
}

int		ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (1)
	{
		if (*str  == ' ' || *str == '\t' || *str == '\n')
			str++;
		else
		{
			while (*str)
			{
				if (*str  == ' ' || *str == '\t' || *str == '\n')
				{
					return(counter);
				}
				str++;
				counter++;
			}
		}
	}
	return (counter);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*copy;

	copy = dest;
	while (*src && *src != ' ' && *src != '\t' && *src != '\n')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (copy);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src);
	copy = (char*)malloc(sizeof(*copy) * (len + 1));
	ft_strcpy(copy, src);
	return (copy);
}

char		**ft_split_whitespaces(char *str)
{
	int		words;
	char	**arr;
	int		i;

	words = counter_words(str);
	arr = (char**)malloc(sizeof(*arr) * (words + 1));
	i = 0;
	while (i < words)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' )
			str++;
		arr[i++] = ft_strdup(str);
		str += ft_strlen(str);
	}
	arr[i] = 0;
	return (arr);
}

int main(void)
{
	char str[] = "Hello, world";
	char	**arr;
	
	arr = ft_split_whitespaces(str);

	
	printf("%s", arr[1]);
}
