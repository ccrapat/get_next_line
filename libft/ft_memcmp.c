/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:09:53 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:17:06 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = (const unsigned char *)b1;
	p2 = (const unsigned char *)b2;
	if (!p1 && !p2)
		return (0);
	while (len-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
