/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:33:25 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:56:25 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strstrdup(const char **str)
{
	char	**ptr;
	int		i;
	int		y;

	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
		i++;
	if (!(ptr = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	while (y < i)
	{
		ptr[y] = ft_strdup(str[y]);
		y++;
	}
	ptr[y] = NULL;
	return (ptr);
}
