/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:00:45 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/11 19:27:20 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		place_it(t_tetri *tetri, t_map *map, t_point *point, char letter)
{
	int i;
	int j;
	int c_x;
	int c_y;

	c_x = point->x;
	c_y = point->y;
	i = 0;
	while (i < tetri->height)
	{
		j = 0;
		while (j < tetri->width)
		{
			if (tetri->cut_out_tetri[i][j] == '#')
				map->map[c_y + i][c_x + j] = letter;
			j++;
		}
		i++;
	}
}

#include <stdio.h>
int			can_i_place_it(t_tetri *tetri, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->height)
	{
		j = 0;
		while (j < tetri->width)
		{
			if (tetri->cut_out_tetri[i][j] == '#' &&
			map->map[y + i][x + j] != '.')
				return (-1);
			j++;
		}
		i++;
	}
	place_it(tetri, map, value_to_point(x, y), tetri->letter);
	return (0);
}

int			solve(t_map *map, t_list *list)
{
	int x;
	int y;
	t_tetri *tetri;

	y = 0;
	if (list == NULL)
		return (0);
	tetri = (t_tetri *)(list->content);
	while (y < map->map_size)
	{
		x = 0;
		while (x < map->map_size)
		{
			if (can_i_place_it(tetri, map, x, y) == 0)
			{
				if (solve(map, list->next) == 0)
					return (0);
				else
					place_it(tetri, map, value_to_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (1);
}

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
	while (solve(map, list) == 1)
	{
		map_size++;
		free_map(map);
		create_new_map(map_size);
	}
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
