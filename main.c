/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:33:43 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/16 13:43:54 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

/*
**		Exit_program : fonction appelee dans le main qui quitte notre
**		programme proprement en cas d'erreur avec le file descriptor
**		ou si check_nlines renvoie une erreur.
*/

int			exit_program(int *fd)
{
	ft_putstr("error\n");
	close(*fd);
	return (-1);
}

/*
**		Main : Debut du programme qui :
**			-gere les erreurs (d'arguments)
**			-appelle les differentes fonctions
**			(solver, liberation de memoire etc...)
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
		ft_putstr_fd("usage : ./fillit [file]\n", 2);
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0 || check_nlines(&fd) == -1)
		return (exit_program(&fd));
	if (((fd = open(av[1], O_RDONLY)) < 0) ||
	((list = read_tetri(fd, &letter)) == NULL))
		return (exit_program(&fd));
	map = solution(list);
	final_free(map, list);
	return (0);
}
