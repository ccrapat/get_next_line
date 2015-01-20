/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:10:13 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:17:27 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned const char		*src_tmp;
	unsigned char			*dst_tmp;

	if (!len)
		return (dst);
	src_tmp = (unsigned const char *)src;
	dst_tmp = (unsigned char *)dst;
	while (len-- > 0)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
