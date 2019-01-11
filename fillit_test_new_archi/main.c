/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:33:43 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/11 16:19:37 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

/*
**		Main : Debut du programme qui :
**			-gere les erreurs (d'arguments)
**			-appelle les differentes fonctions
**			(solver, affichage, liberation de memoire etc...)
*/

int			main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;
	int		fd;
	char	letter;

	letter = 'A';
	if (ac != 2)
	{
		ft_putstr_fd("Need one argument\n", 2);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if ((fd < 0) || ((list = read_tetri(fd, &letter)) == NULL))
	{
		ft_putstr_fd("error\n", 2);
		return (-1);
	}
	map = solution(list);
	print_solution(map);
	final_free(map, list);
	return (0);
}
