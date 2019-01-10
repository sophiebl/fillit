/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:47:34 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/24 00:18:43 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (((unsigned char*)s)[len] == (unsigned char)c)
			return (&((char*)s)[len]);
		len--;
	}
	if (c == '\0')
		return (&((char *)s)[len]);
	return (NULL);
}
