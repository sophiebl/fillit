/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:54:58 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/20 17:09:44 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t nb)
{
	size_t i;

	i = 0;
	while ((s1[i] || s2[i]) && nb > i)
	{
		if ((((unsigned char*)s1)[i] > ((unsigned char *)s2)[i]) ||
				(((unsigned char *)s1)[i] < ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
