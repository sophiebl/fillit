/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_alloc_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:25 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/11 13:42:14 by kboucaul         ###   ########.fr       */
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
