/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:13:26 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 07:45:21 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s, const char *append)
{
	char	*save;

	save = s;
	while (*s)
		s++;
	while (*append)
	{
		*s = *append;
		s++;
		append++;
	}
	*s = '\0';
	return (save);
}
