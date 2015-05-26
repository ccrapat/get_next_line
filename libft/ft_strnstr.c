/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:23 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 17:49:49 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0)
	{
		if (n < ft_strlen(s2))
			break ;
		if (*s1 == '\0')
			break ;
		s1++;
		n--;
	}
	if (n < ft_strlen(s2) || ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	else if (*s1 == '\0' && n == 0)
		return (NULL);
	return ((char*)s1);
}
