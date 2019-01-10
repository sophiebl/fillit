/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:57:43 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/10 18:26:54 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		Check_count	:	Retourne 0 si il n'y a pas d'erreur
**		ou -1 si il y a au moins 1 erreur.
**			-Check si les caracteres du tetri sont ('#', '.', '\n')
**			-Check si il y a exactement 4 '#'
**			-Check les liens entre les blocs
*/

int		check_counts(char *tetri, int rd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (rd == 21 && tetri[20] != '\n')
		return (-1);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(tetri[i] == '#' || tetri[i] == '.'))
				return (-1);
			if ((tetri[i] == '#') && (count >= 4))
				return (-1);
			else if ((count < 4) && (tetri[i] == '#'))
				count++;
		}
		else if (tetri[i] != '\n')
			return (-1);
		i++;
	}
	if (check_link(tetri) == 0)
		return (-1);
	return (0);
}

/*
**		Check_link	:	Retourne 0 si le nombre de liens n'est pas bon
**		ou bien retourne le nombre de liens.
**			
**			ex1 :
**					..##
**					...#	Ici 6 liens
**					...#		-->3 liens 1ere ligne	
**					....		-->2 liens 2eme ligne
**								-->1 lien 3eme ligne
**
**			ex2 : (cas particulier)
**					
**					.##.
**					.##.	Ici 8 liens (car chaque bloque a 2 liens)
**					....			-->4 liens 1ere ligne
**					....			-->4 liens 2eme ligne
*/

int		check_link(char *tetri)
{
	int	link;
	int	index;

	link = 0;
	index = 0;
	while (index < 20)
	{
		if (tetri[index] == '#')
		{
			if (((index + 1) < 20) && tetri[index + 1] == '#')
				link++;
			if (((index - 1) >= 0) && tetri[index - 1] == '#')
				link++;
			if (((index + 5) < 20) && tetri[index + 5] == '#')
				link++;
			if (((index - 5) >= 0) && tetri[index - 5] == '#')
				link++;
		}
		index++;
	}
	if (link == 6 || link == 8)
		return (link);
	else
		return (0);
}
