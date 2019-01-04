/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:06:03 by sboulaao          #+#    #+#             */
/*   Updated: 2018/12/03 20:54:08 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t nb)
{
	size_t i;

	i = 0;
	while (i < nb)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)dest)[i] == (char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
