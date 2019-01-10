/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:40:24 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/24 19:42:19 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countw(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}
