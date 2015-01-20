/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 23:02:27 by ccrapat           #+#    #+#             */
/*   Updated: 2015/01/20 01:55:56 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_get	*ft_init_and_free_ptr(t_get **ptr, int choice)
{
	t_get		*tmp;

	tmp = *ptr;
	if (choice == 0)
	{
		tmp = (t_get *)malloc(sizeof(t_get));
		tmp->stock = NULL;
	}
//	else
//	{
//		free(tmp);
//		tmp = NULL;
//	}
	return (tmp);
}

static int		ft_make_line(t_get *ptr, char **line)
{
	int			i;

	i = 0;
	while (ptr->stock[i] != '\n' && ptr->stock[i] != '\0')
		i++;
	if (ptr->stock[i] == '\0')
	{
		*line = ft_strdup(ptr->stock);
		ft_strdel(&ptr->stock);
		return (1);
	}
	ptr->stock[i] = '\0';
	*line = ft_strdup(ptr->stock);
	ptr->stock[i] = '\n';
	ptr->tmp = ptr->stock;
	ptr->stock = ft_strdup(&ptr->tmp[i + 1]);
	ft_strdel(&ptr->tmp);
	return (1);
}

static void		ft_join_reader(t_get *ptr)
{
	if (!ptr->stock)
		ptr->stock = ft_strdup(ptr->reader);
	else
	{
		ptr->tmp = ptr->stock;
		ptr->stock = ft_strjoin(ptr->tmp, ptr->reader);
		ft_strdel(&ptr->tmp);
	}
}

int				get_next_line(int fd, char **line)
{
	static	t_get		*ptr;

	if (fd < 0 || (fd > 0 && fd < 3) || line == NULL)
		return (-1);
	if (!ptr)
		ptr = ft_init_and_free_ptr(&ptr, 0);
	if (ptr->stock != NULL && ptr->stock[0] != '\0')
		if (ft_strchr(ptr->stock, '\n') != NULL)
			return (ft_make_line(ptr, line));
	while ((ptr->ret = read(fd, ptr->reader, BUFF_SIZE)) != 0)
	{
		if (ptr->ret < 0 || fd < 0)
		{
			ft_init_and_free_ptr(&ptr, 1);
			return (-1);
		}
		ptr->reader[ptr->ret] = '\0';
		ft_join_reader(ptr);
		if (ft_strchr(ptr->stock, '\n') != NULL)
			return (ft_make_line(ptr, line));
	}
	if (ptr->stock != NULL && ptr->stock[0] != '\0')
		return (ft_make_line(ptr, line));
	ptr = ft_init_and_free_ptr(&ptr, 1);
	return (0);
}
