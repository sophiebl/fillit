/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:22:58 by sboulaao          #+#    #+#             */
/*   Updated: 2018/12/03 16:58:07 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append(t_list **final, t_list *elem)
{
	t_list *new;

	if (final && elem)
	{
		if (!(new = ft_lstnew(elem->content, elem->content_size)))
			return ;
		while ((*final)->next)
			final = &(*final)->next;
		(*final)->next = new;
	}
}
