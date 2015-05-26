/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:31:41 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 18:01:01 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int		ft_next(const char *str, char charset, int i)
{
	int		first;
	int		result;

	result = 0;
	first = i;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
			break ;
		i++;
	}
	result = i - first;
	return (result);
}

static int		ft_charset(const char *str, char charset)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
		{
			result++;
			while (str[i] == charset)
				i++;
		}
		i++;
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		n;

	i = 0;
	n = 0;
	split = (char **)malloc(sizeof(char *) * (ft_charset(s, c) + 1));
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		split[n] = ft_strsub(s, i, ft_next(s, c, i));
		i += ft_next(s, c, i);
		n++;
	}
	split[n] = NULL;
	return (split);
}
