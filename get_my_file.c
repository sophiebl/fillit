/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_my_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:45:29 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/16 15:17:12 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

/*
**		Get_Coord : Initialise la structure t_point aux
**		coordonnees (a(x,y), b(x, y))
**		---> Cela permmetra de les decouper puis de les placer.
*/

void			get_coord(char *tetri, t_point *coord_min, t_point *coord_max)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			if (i / 5 < coord_min->y)
				coord_min->y = i / 5;
			if (i / 5 > coord_max->y)
				coord_max->y = i / 5;
			if (i % 5 < coord_min->x)
				coord_min->x = i % 5;
			if (i % 5 > coord_max->x)
				coord_max->x = i % 5;
		}
		i++;
	}
}

/*
**		Cut_the_tetri : Renvoie le tetrimino decoupe  en fonction
**		des limites recuperes.
**		Il renvoie le plus petit rectangle.
*/

char			**cut_the_tetri(char *str, t_point *coord_min,
				t_point *coord_max)
{
	int			i;
	int			width;
	int			height;
	char		**cut_out_tetri;

	i = 0;
	width = coord_max->x - coord_min->x + 1;
	height = coord_max->y - coord_min->y + 1;
	cut_out_tetri = (char **)malloc(sizeof(char *) * height);
	if (cut_out_tetri == NULL)
		return (NULL);
	while (i < height)
	{
		cut_out_tetri[i] = ft_strndup((str +
		(coord_min->x) + (i + coord_min->y) * 5), width + 1);
		i++;
	}
	return (cut_out_tetri);
}

/*
**		Get_tetri : Renvoie une structure contenant le
**		tetrimino (decoupe) et ses proprietes
**			-D'abord on recupere les coordonnes des "limites"
**			-Ensuite on coupe notre tetrimino
**			-On cree et initialise notre structure tetri
**			-On libere la memoire occupee par la structure t_point
*/

t_tetri			*get_tetri(char *str, char letter)
{
	t_point		*coord_min;
	t_point		*coord_max;
	char		**cut_out_tetri;
	t_tetri		*tetri;

	coord_min = value_to_point(3, 3);
	coord_max = value_to_point(0, 0);
	if (coord_min == NULL || coord_max == NULL)
		return (NULL);
	get_coord(str, coord_min, coord_max);
	if ((cut_out_tetri = cut_the_tetri(str, coord_min, coord_max)) == NULL)
		return (NULL);
	tetri = value_to_tetri(cut_out_tetri, coord_max->x - coord_min->x + 1,
	coord_max->y - coord_min->y + 1, letter);
	if (tetri == NULL)
		return (NULL);
	free_point(&coord_min, &coord_max);
	return (tetri);
}

/*
**		Read_tetri : Renvoie un pointeur sur liste contenant l'ensemble des
**		tetriminos(verifies et decoupes).
**			-On lit 20 caracteres pour obtenir normalement notre tetrimino
**			-On le verifie et on le remplace par la lettre en question
**			-On cree autant de maillons que nous avons de tetriminos
**			-On libere la memoire
**			-On retourne la liste pour obtenir les tetriminos dans l'ordre
**			du fichier car LIFO
*/

t_list			*read_tetri(int fd, char *letter)
{
	char		*stock;
	int			rd;
	t_list		*list;
	t_tetri		*tetri;

	if (!(stock = (char *)malloc(21)))
		return (NULL);
	list = NULL;
	while ((rd = read(fd, stock, 21)) >= 20)
	{
		if (check_counts(stock, rd) ||
		(tetri = get_tetri(stock, (*letter)++)) == NULL)
		{
			ft_strdel(&stock);
			return (free_list_tetris(list));
		}
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tetri)));
		ft_memdel((void **)&tetri);
	}
	ft_strdel(&stock);
	if (rd != 0)
		return (free_list_tetris(list));
	ft_lstrev(&list);
	return (list);
}
