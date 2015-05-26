/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 23:02:09 by ccrapat           #+#    #+#             */
/*   Updated: 2015/02/18 18:27:49 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 4096

typedef struct		s_get
{
	char		reader[BUFF_SIZE + 1];
	char		*stock[256];
	char		*tmp;
	int			i;
	int			ret;
}					t_get;

int					get_next_line(int fd, char **line);

#endif
