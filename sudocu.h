/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudocu.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 22:58:51 by gstiedem          #+#    #+#             */
/*   Updated: 2018/09/30 23:08:03 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	determine(int x, int y, int print);

int        place(int y, int x, char a);

void    check(int y, int x, int print);

int check_er(int argc, char **argv);

void	print_s(void);

int		ft_strlen(char *c);
