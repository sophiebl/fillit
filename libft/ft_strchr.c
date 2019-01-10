/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:58:11 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/24 19:33:38 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char*)s)[i]);
		i++;
	}
	if (((unsigned char*)s)[i] == '\0' && (unsigned char)c == '\0')
		return (&((char*)s)[i]);
	return (NULL);
}
