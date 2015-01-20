/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:30:14 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 10:13:14 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		s[i] = '\0';
		i++;
	}
	s[i] = '\0';
	return (s);
}
