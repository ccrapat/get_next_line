/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:32:29 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 17:34:55 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strstr(const char *big, const char *little)
{
	if (!*little)
		return ((char *)big);
	while (ft_strncmp(big, little, ft_strlen(little)) != 0)
	{
		if (!*big)
			return (NULL);
		big++;
	}
	return ((char *)big);
}
