/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:32:49 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:54:35 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		**ft_strstrcpy(char **dest, char **src)
{
	char		**save_dest;

	save_dest = dest;
	while (*src)
	{
		ft_strcpy(*dest, *src);
		*dest = *dest + 1;
		*src = *src + 1;
	}
	*dest = NULL;
	return (save_dest);
}
