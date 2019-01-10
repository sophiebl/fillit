/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:23:22 by sboulaao          #+#    #+#             */
/*   Updated: 2018/12/01 15:34:12 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					**ft_strsplit(char const *s, char c)
{
	int		j;
	int		len;
	char	**tab;

	j = 0;
	if (!s || !c)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * (ft_countw(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_size_word(s, c);
			if (!(tab[j] = ft_strnew(len)))
				return (NULL);
			ft_strncpy(tab[j++], s, len);
			s += len;
		}
	}
	tab[j] = NULL;
	return (tab);
}
