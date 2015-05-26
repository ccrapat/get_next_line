/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:07:50 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:10:45 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*lst;
	t_list		*lst_next;

	lst = *alst;
	lst_next = lst->next;
	while (lst->next)
	{
		ft_lstdelone(&lst, del);
		lst = lst_next;
		lst_next = lst->next;
	}
	ft_lstdelone(&lst, del);
	ft_memdel((void **)alst);
}
