/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:10:35 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:44:28 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	const char		*src_tmp;
	char			*dest_tmp;
	char			*array_tmp;
	size_t			n_tmp;

	if (n <= 0)
		return (dest);
	if (!(array_tmp = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	n_tmp = n;
	array_tmp += n;
	src_tmp = (const char *)src;
	src_tmp += n;
	while (n_tmp--)
		*--array_tmp = *--src_tmp;
	dest_tmp = (char *)dest;
	dest_tmp += n;
	array_tmp += n;
	while (n-- > 0)
		*--dest_tmp = *--array_tmp;
	ft_strdel(&array_tmp);
	return (dest);
}
