/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:33:43 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/10 17:46:11 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

/*
**		Print_map : affiche a l'ecran la solution trouvee
*/

void    print_solution(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->map[i]);
		i++;
	}
}

/*
 **		Main : Debut du programme qui :
 **			-gere les erreurs (d'arguments)
 **			-appelle les differentes fonctions
 **			(solver, affichage, liberation de memoire etc...)
 */

int			main(int ac, char **av)
{
	t_list	*list;
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Need one argument\n", 2);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if ((fd < 0) || ((list = read_tetri(fd)) == NULL))
	{
		ft_putstr_fd("error\n", 2);
		return (-1);
	}
	return (0);
}
