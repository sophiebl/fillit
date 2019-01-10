/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:53:08 by sboulaao          #+#    #+#             */
/*   Updated: 2018/11/29 18:49:19 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(int *n, int *len)
{
	int sign;

	sign = 0;
	if (*n < 0)
	{
		sign = 1;
		*n *= -1;
		*len += 1;
	}
	return (sign);
}

static int		ft_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (2);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*tab;
	int		sign;

	len = ft_size(n);
	sign = ft_sign(&n, &len);
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((tab = (char *)ft_memalloc(len)) == NULL)
		return (NULL);
	tab[--len] = '\0';
	while (len--)
	{
		tab[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		tab[0] = '-';
	return (tab);
}
