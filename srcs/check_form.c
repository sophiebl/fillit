/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:26:03 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 17:57:49 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"
#include "libft.h"

int		check_form(char **tab, int index)
{
	int i;
	char **tetri;

	i = 0;
	tetri = ft_split(tab[index], '\n');
	if ((check_line(tetri) + check_row(tetri) + check_square(tetri) + check_z(tetri) + check_l(tetri) + check_bow(tetri)) != 1)
		return (-1);
	return (0);
}

int		check_line(char **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(tab[i], "####") != 0)
			i++;
		else
			return (1);
	}
	return (0);
}

int		check_row(char **tab)
{
	int i;
	int j;

	while (tab[0][j])
	{
		if (tab[0][j] == '#')
			break ;
		else if (j < 4)
			j++;
		else
			return (0);
	}
	if (tab[1][j] == '#' && tab[2][j] == '#' && tab[3][j] == '#')
		return (1);
	return (0);
}
