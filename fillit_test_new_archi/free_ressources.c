/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:44:18 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/10 19:10:16 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
**		Liberation de la memoire utilisee pour la structure tetri
*/

void		free_tetris(t_tetri *tetri)
{
	int		i;

	i = 0;
	while (i < tetri->height)
	{
		ft_strdel(&(tetri->cut_out_tetri[i]));
		i++;
	}
	ft_memdel((void **)(&(tetri->cut_out_tetri)));
	ft_memdel((void **)&tetri);
}

/*
**		Liberation de la memoire utilisee pour la structure point
*/

void		free_point(t_point **coord_min, t_point **coord_max)
{
	ft_memdel((void **)coord_min);
	ft_memdel((void **)coord_max);
}

/*
**		Liberation de la memoire utilisee pour la liste chainee
*/

t_list		*free_list_tetris(t_list *list)
{
	t_tetri *tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_tetri *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

/*
**		Liberation de la memoire utilisee pour la structure map
*/

void		free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_strdel(&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}
