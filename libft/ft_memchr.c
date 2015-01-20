/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:09:35 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:16:27 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void		*ft_memchr(void *b, int c, size_t len)
{
	if (!len)
		return (b);
	while (len-- > 0)
	{
		if (*(unsigned char *)b == (unsigned char)c)
			return (b);
		b = (unsigned char *)b + 1;
	}
	return (NULL);
}
