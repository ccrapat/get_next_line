/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:07:10 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:43:57 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char		*malloc_size_n(int n, size_t *len, int *multi)
{
	char		*s;

	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*multi = 1;
	while (n / *multi < -9)
	{
		*multi *= 10;
		*len += 1;
	}
	if (!(s = (char *)malloc(sizeof(char) * (*len + 1))))
		return (NULL);
	return (s);
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	int			multi;
	char		*s;

	i = 0;
	if (!(s = malloc_size_n(n, &len, &multi)))
		return (NULL);
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (multi >= 1)
	{
		s[i++] = -(n / multi % 10) + '0';
		multi /= 10;
	}
	s[i] = '\0';
	return (s);
}
