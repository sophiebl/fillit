/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:36:53 by sboulaao          #+#    #+#             */
/*   Updated: 2018/12/01 15:37:24 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *final;

	if (!lst)
		return (NULL);
	if (!(final = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ft_append(&final, f(lst));
		lst = lst->next;
	}
	return (final);
}
