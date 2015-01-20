/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:31:41 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:54:08 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	strcchar(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static size_t	ft_check_split(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(ptr = (char **)malloc(sizeof(char *) * strcchar(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ptr[i] = ft_strsub(s, 0, ft_check_split(s, c));
			s += ft_strlen(ptr[i]);
			i++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
