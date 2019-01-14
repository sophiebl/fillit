/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_alloc_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:25 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/14 13:39:01 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Value_to_point : Retourne une structure (point)
**		allouee et initialisee aux valeurs de parametres
*/

t_point			*value_to_point(int x, int y)
{
	t_point		*point;

	point = malloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

/*
**		Value_to_tetri : Retourne une structure (tetri)
**		allouee et initialisee aux valeurs de parametres
*/

t_tetri			*value_to_tetri(char **cut_out_tetri,
		int width, int height, char letter)
{
	t_tetri		*tetri;

	tetri = malloc(sizeof(t_tetri));
	if (tetri == NULL)
		return (NULL);
	tetri->cut_out_tetri = cut_out_tetri;
	tetri->width = width;
	tetri->height = height;
	tetri->letter = letter;
	return (tetri);
}

/*
**		Create_new_map : Renvoie une structure contenant
**		la map creee, initialise avec des '.' et ses proprietes.
*/

t_map			*create_new_map(int size)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map_size = size;
	map->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	map = init_new_map(map);
	return (map);
}

/*
**		Init_new_map : Remplie et alloue chaque ligne de la
**		map avec des '.'.
*/

t_map			*init_new_map(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->map_size)
	{
		j = 0;
		map->map[i] = (char *)malloc(sizeof(char) * (map->map_size + 1));
		while (j < map->map_size)
		{
			map->map[i][j] = '.';
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = "\0";
	return (map);
}
