/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:00:45 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/11 17:53:33 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_map		*solution(t_list *list)
{
	t_map	*map;
	int		map_size;
	int		nb_tetris;

	nb_tetris = ft_lstcount(list);
	map_size = 2;
	while ((map_size * map_size) < (nb_tetris * 4))
		map_size++;
	map = create_new_map(map_size);
	if (map == NULL)
		return (NULL);
	return (map);
}

/*
**      Print_map : affiche a l'ecran la solution trouvee
*/

void		print_solution(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->map_size)
	{
		ft_putendl(map->map[i]);
		i++;
	}
}
