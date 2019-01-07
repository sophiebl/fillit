/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:48:18 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/07 15:43:18 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char			**my_alloc_tab(char *str, int *nb_tetris)
{
	size_t		i;
	char		**tab;

	i = 0;
	*nb_tetris = ft_strlen(str) / 16;
	tab = (char **)malloc(sizeof(char *) * *nb_tetris + 1);
	while (i < (size_t)*nb_tetris)
	{
		tab[i] = (char *)malloc(6);
		ft_bzero(tab[i], 6);
		i++;
	}
	tab[i] = "\0";
	return (tab);
}

int				take_tetri(const int fd)
{
	char		*line;
	char		*str;
	char		**tab;
	int			nb_tetris;
	int			i;

	i = 0;
	line = NULL;
	str = NULL;
	str = my_get_line(&fd, line);
	close(fd);
	nb_tetris = ft_strlen(str) / 16;
	ft_putnbr(nb_tetris);
	tab = str_to_tab(str);
	if (check_size_tetri(tab, nb_tetris) == -1)
		return (-1);
<<<<<<< HEAD
	if (!solve(tab, nb_tetris))
		write(1, "error\n", 6);
=======
	while (i < nb_tetris)
	{
		if (check_form(tab, i) != 0)
		{
			ft_putstr_fd("error\n", 2);
			exit(84);
		}
		i++;
	}
>>>>>>> b450694371222e14e30004b85a38fae2217db09d
	tab = put_letters(tab, nb_tetris);
	print_tab(tab, nb_tetris);
	return (0);
}
