/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:37 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 09:13:39 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	size_t		n;

	n = ft_strlen((char *)s);
	s += n;
	while (n + 1)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		n--;
	}
	return (NULL);
}
