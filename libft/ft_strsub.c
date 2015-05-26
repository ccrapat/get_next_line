/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:33:51 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 17:59:52 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(len + 1);
	if (dst == NULL)
		return (NULL);
	while (len > 0)
	{
		dst[i] = s[start];
		start++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
