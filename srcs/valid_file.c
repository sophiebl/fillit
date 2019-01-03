/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:20:39 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 15:17:25 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri.h"
#include "libft.h"
#include <stdio.h>

/*
int		check_link(char **tab)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < nb_tetris)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				while (
		}
		j = 0;
		i = 0;
	}
	return (0);
}
*/
int		check_size_tetri(char **tab, int nb_tetris)
{
	int count;
	int i;
	int j;

	count = 0;
	j = 0;
	i = 0;
	while (i < nb_tetris)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				count++;
			j++;
		}
		if (count != 4)
		{
			ft_putstr_fd("Error here (check_size_tetri)", 2);
			return (-1);
		}
		count = 0;
		i++;
		j = 0;
	}
	return (0);
}

int		check_nb_lines(char **tab, int nb_tetris)
{
	int i;

	i = 0;
	while (i < nb_tetris)
	{
		if (ft_strlen(tab[i]) != 16)
		{
			ft_putstr_fd("Bad size of line\n", 2);
			return (-1);
		}
		else
			i++;
	}
	return (0);
}
