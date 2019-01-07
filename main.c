/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:01:17 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/04 18:12:36 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "include/fillit.h"

int		main(int ac, char **av)
{
	int fd;
	int fd2;
	int	fd3;

	fd = 0;
	fd2 = 0;
	fd3 = 0;
	if (ac != 2)
	{
		ft_putstr_fd("We need one argument\n", 2);
		return(0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[1], O_RDONLY);
		fd3 = open(av[1], O_RDONLY);
		if (fd < 0 || fd2 < 0 || fd3 < 0)
			return (-1);
		check_spaces(fd);
		check_tetris_nb_lines(fd2);
		take_tetri(fd3);
	}
	return (0);
}
