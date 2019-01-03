/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:48:18 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 17:10:18 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "tetri.h"

char **my_alloc_tab(char *str, int *nb_tetris)
{
	size_t 	i;
	char 	**tab;

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

int		take_tetri(const int fd)
{
	char	*line;
	char	*str;
	char 	**tab;
	int		nb_tetris;

	line = NULL;
	str = NULL;
	str = my_get_line(&fd, line);
	close (fd);
	nb_tetris = ft_strlen(str) / 16;
	tab = str_to_tab(str);
	if (check_size_tetri(tab, nb_tetris) == -1)
		return (-1);
	tab = put_letters(tab, nb_tetris);
	print_tab(tab, nb_tetris);
	return (0);
}
