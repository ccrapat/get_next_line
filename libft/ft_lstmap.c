/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:44 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:44:10 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst2;
	t_list		*lst2_head;

	if (!lst || !f)
		return (NULL);
	if (!(lst2 = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	lst2_head = lst2;
	while (lst)
	{
		if (!(lst2 = (*f)(lst)))
			return (NULL);
		lst = lst->next;
		lst2 = lst2->next;
	}
	lst2 = NULL;
	return (lst2_head);
}
