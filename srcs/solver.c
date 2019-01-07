/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:44:53 by sboulaao          #+#    #+#             */
/*   Updated: 2019/01/04 19:31:53 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

tetri_lst	*get_tetrimonos_lst(char **tab, int nb_tetri)
{
	tetri_lst	*tetri;

	if (!(tetri = malloc(sizeof(tetri_lst))))
				return (NULL);
	if (**tab == NULL || nb_tetri == 0)
	{
		tetri_lst->shape_tetri == NULL;
		tetri_lst->nb_tetri == 0;
	}
	else
	{
		if (!(tetri_lst->shape_tetri = malloc(sizeof(*tab))))
		{
			free(tetri);
			return (NULL);
		}
		tetri_lst->shape_tetri = ft_strcpy(tetri_lst->shape_tetri, *tab);		
	}
}

int		solve(char **tab, int nb_tetris)
{
	get_tetrimonos_lst(tab, nb_tetri);
	return (0);
}
