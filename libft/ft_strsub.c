/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:33:51 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 09:51:13 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (!s || !len)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s += start;
	while (len--)
	{
		ptr[i] = s[i];
		if (ptr[i] == '\0')
			return (ptr);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
