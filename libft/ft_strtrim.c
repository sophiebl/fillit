/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:21:58 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/29 14:23:07 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	int		start;
	int		size;

	if (!s)
		return (NULL);
	if (!s[0])
		return (ft_strdup(""));
	start = 0;
	while (ft_is_separator(s[start]))
		start++;
	if (!s[start])
		return (ft_strdup(""));
	size = ft_strlen(s + start) - 1;
	while (ft_is_separator(s[size + start]) && size >= 0)
		size--;
	size++;
	return (ft_strsub(s, start, size));
}
