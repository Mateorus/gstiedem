/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:57:53 by gstiedem          #+#    #+#             */
/*   Updated: 2018/10/01 22:49:08 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			count_words(char *str)
{
	int		num;
	char	*c;

	num = 0;
	c = str;
	while (*c)
	{
		if((*c == ' ' || *c == '\t' || *c == '\n' || *c == 0) && *(c-1))
			;
		else(*c != ' ' || *c != '\t' || *c != '\n' || *c != 0)
			;
		c++;
	}
	return (num);
}
/*
char		**ft_split_whitespaces(char *str)
{
	char	**arr;

	arr = (char**)malloc(sizeof(*arr) * 
}

*/


int main(void)
{
	char	arr[] = "Hello, world!";
	int		x;

	x = count_words(arr);
	printf("%i", x);

}
