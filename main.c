/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 22:54:52 by gstiedem          #+#    #+#             */
/*   Updated: 2018/09/30 23:06:49 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(char *c)
{
	int	counter;

	counter = 0;
	while(*c)
	{
		counter++;
		c++;
	}
	return (counter);
}

void    print_s(void)
{
    int    i;
    int    j;
    
    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            write(1, &g_array[i][j], 1);
            if (j != 8)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}


