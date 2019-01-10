/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 02:08:05 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/24 02:26:50 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_size_word(char const *s, char c)
{
	int length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	return (length);
}
