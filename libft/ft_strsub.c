/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:28:32 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/29 17:47:48 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!(str = ft_strnew(len)))
		return (NULL);
	if (!s || (start > ft_strlen(s)))
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	return (str);
}
