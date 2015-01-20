/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:52:57 by ccrapat           #+#    #+#             */
/*   Updated: 2014/11/10 09:54:17 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int	resultat;
	int	a;

	resultat = 0;
	a = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' ||
	*nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			a = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		resultat *= 10;
		resultat = resultat + (*nptr - '0');
		nptr++;
	}
	return (a * resultat);
}
