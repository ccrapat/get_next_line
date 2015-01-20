/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:26:22 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:32:34 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *dst, const char *append, size_t len)
{
	size_t	len_tmp;
	char	*save;

	save = dst;
	len_tmp = 0;
	while (*dst != '\0')
		dst++;
	while (len_tmp++ < len && *append != '\0')
	{
		*dst = *append;
		dst++;
		append++;
	}
	*dst = '\0';
	return (save);
}
