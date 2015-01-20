/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:34:15 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 06:40:29 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_check_char(char const *s)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (*s != '\n' && *s != ' ' && *s != '\t')
		{
			i++;
		}
		s++;
	}
	if (i == 0)
		return (0);
	return (1);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	y;
	size_t	space;

	i = 0;
	space = 0;
	if (!s)
		return (NULL);
	if (ft_check_char(s) == 0)
		return (ft_strsub(s, ft_strlen(s), 1));
	y = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == ',')
	{
		i++;
		space++;
	}
	while (s[y] == '\n' || s[y] == ' ' || s[y] == '\t' || s[y] == ',')
	{
		y--;
		space++;
	}
	return (ft_strsub(s, i, ft_strlen(s) - space));
}
