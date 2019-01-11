/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:00:45 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/11 14:34:00 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_map		*solution(t_list *list)
{
	t_map	*map;
	int		map_size;

	(void)list;
	map_size = 2;
	map = create_new_map(map_size);
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
