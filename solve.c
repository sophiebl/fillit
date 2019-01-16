/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:00:45 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/16 14:03:59 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**			Place_it : Fonction qui place le tetrimino dans la map finale
**			grace a la verification de can_i_place_it.
**			Le principe est de recuperer les positions x et y de map et de
**			placer le premier block a ces coordonnees.
**			Ensuite, il s'agira de reproduire la forme exacte du tetrimino.
**			Puis de free la structure point qui servira au prochain tetrimino.
**			(RAPPEL) :
**					  -tetri->width represente la largeur du tetrimino decoupe
**					  -tetri->height represente la hauteur du tetrimino decoupe
**			EXEMPLE:
**						..#.
**						..#.	Width  = 2
**						.##.	Height = 3
**						....
*/

void			place_it(t_tetri *tetri, t_map *map,
				t_point *point, char letter)
{
	int			i;
	int			j;
	int			c_x;
	int			c_y;

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
	ft_memdel((void **)&point);
}

/*
**			Can_i_place_it : Renvoie -1 si on ne peut pas placer
**			le tetriminos aux coordonnes donnees (x, y).
*/

int				can_i_place_it(t_tetri *tetri, t_map *map, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	while ((i < tetri->height) && ((y + i) < map->map_size))
	{
		j = 0;
		while ((j < tetri->width) && ((x + j) < map->map_size))
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

/*
**			Solve : Fonction renvoyant -1 si la taille de map est trop
**			petite ou 0 si l'appel recursif de solve a permi de trouver
**			la solution.
**			Si la fonction can_i_place_it nous renvoie 0, on peut placer
**			le tetrimino a cet endroit. Mais on doit regarder si ce choix
**			nous permettra de placer le suivant et ainsi de suite.
**			--->backtracking
**			Dans le cas ou ce choix s'est avere mauvais, on replace les
**			points aux coordonnes chosis.
**
**			(!) Les conditions des deux boucles while permettent de "limiter"
**				les coordonnees que l'on veut traiter.
**					|
**					|--> Exemple :
**
**					avec une taille de 4 et un tetrimino :	....
**															##..
**															.##.
**															....
**
**					Notre y (indice de ligne) ne peut pas etre superieur a la
**					taille de notre map + la taille en hauteur de notre tetri.
**						Soit : 4 - 2 = 2
**					La, l'indice limite en hauteur (y) est 2 (pas +)
**					Meme principe pour la limite en largeur (x).
*/

int				solve(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetri		*tetri;

	y = 0;
	if (list == NULL)
		return (0);
	tetri = (t_tetri *)(list->content);
	while (y <= (map->map_size - tetri->height))
	{
		x = 0;
		while (x <= (map->map_size - tetri->width))
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

/*
**			Solution : Renvoie une structure et est la base de notre solveur.
**			Tant que nous n'avons pas fini de resoudre la map (solve-->1)
**			a cause de la taille de map, on recommence
**			(mais ce n'est pas le backtracking).
**			On affiche la map a la fin de la fonction.
*/

t_map			*solution(t_list *list)
{
	t_map		*map;
	int			map_size;
	int			nb_tetris;

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
		map = create_new_map(map_size);
	}
	print_solution(map);
	return (map);
}

/*
**      Print_map : affiche a l'ecran la solution trouvee (map) du type char **.
*/

void			print_solution(t_map *map)
{
	int			i;

	i = 0;
	while (i < (map->map_size))
	{
		ft_putendl(map->map[i]);
		i++;
	}
}
