/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:19:19 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:50:04 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	int	len_dest;
	int	len_src;
	int	i;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	while (*dest != '\0')
		dest++;
	while ((size_t)(len_dest + i + 1) < dest_size)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	if ((size_t)len_dest < dest_size)
		return (len_dest + len_src);
	else
		return (dest_size + len_src);
}
