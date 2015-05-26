/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 23:02:27 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 18:24:32 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_get	*ft_init_and_free_ptr(t_get **ptr, int choice)
{
	t_get		*tmp;

	tmp = *ptr;
	if (choice == 0)
		tmp = (t_get *)malloc(sizeof(t_get));
	return (tmp);
}

static int		ft_make_line(t_get *ptr, char **line, int fd)
{
	int			i;

	i = 0;
	while (ptr->stock[fd][i] != '\n' && ptr->stock[fd][i] != '\0')
		i++;
	if (ptr->stock[fd][i] == '\0')
	{
		*line = ft_strdup(ptr->stock[fd]);
		ft_strdel(&ptr->stock[fd]);
		return (1);
	}
	ptr->stock[fd][i] = '\0';
	*line = ft_strdup(ptr->stock[fd]);
	ptr->stock[fd][i] = '\n';
	ptr->tmp = ptr->stock[fd];
	ptr->stock[fd] = ft_strdup(&ptr->tmp[i + 1]);
	ft_strdel(&ptr->tmp);
	return (1);
}

static void		ft_join_reader(t_get *ptr, int fd)
{
	if (!ptr->stock[fd])
		ptr->stock[fd] = ft_strdup(ptr->reader);
	else
	{
		ptr->tmp = ptr->stock[fd];
		ptr->stock[fd] = ft_strjoin(ptr->tmp, ptr->reader);
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
	if (ptr->stock[fd] != NULL && ptr->stock[fd][0] != '\0')
		if (ft_strchr(ptr->stock[fd], '\n') != NULL)
			return (ft_make_line(ptr, line, fd));
	while ((ptr->ret = read(fd, ptr->reader, BUFF_SIZE)) != 0)
	{
		if (ptr->ret < 0 || fd < 0)
		{
			ft_init_and_free_ptr(&ptr, 1);
			return (-1);
		}
		ptr->reader[ptr->ret] = '\0';
		ft_join_reader(ptr, fd);
		if (ft_strchr(ptr->stock[fd], '\n') != NULL)
			return (ft_make_line(ptr, line, fd));
	}
	if (ptr->stock[fd] != NULL && ptr->stock[fd][0] != '\0')
		return (ft_make_line(ptr, line, fd));
	ptr = ft_init_and_free_ptr(&ptr, 1);
	return (0);
}
