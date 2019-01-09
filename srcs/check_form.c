/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:26:03 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/09 12:57:08 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_form(char **tab, int index)
{
	if (check_links(tab[index]) == 0)
		return (0);
	return (-1);
}

int		check_links(char *tab)
{
	int i;
	int link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (tab[i] == '#')
		{
			if (((i + 1) < 20) && tab[i + 1] == '#')
				link++;
			if (((i - 1) > -1) && tab[i - 1] == '#')
				link++;
			if (((i + 5) < 20) && tab[i + 5] == '#')
				link++;
			if (((i - 5) > -1) && tab[i - 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 8 || link == 6)
		return (0);
	return (-1);
}
