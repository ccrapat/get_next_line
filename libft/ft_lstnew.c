/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:53 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:14:10 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	if (!content || !content_size)
		return (NULL);
	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	if (!(lst->content = malloc(content_size)))
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
