/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_before.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:17:32 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 13:14:32 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tetri.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		check_spaces(int fd)
{
	char *line;
	int spaces;

	spaces = 0;
	get_next_line(fd, &line);
	if (ft_strcmp(line, "") == 0)
	{
		ft_putstr_fd("error with spaces\n", 2);
		exit (84);
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{ 
		if ((ft_strcmp(line, "") == 0) && (spaces == 0))
			spaces = 1;
		else if ((ft_strcmp(line, "") == 0) && (spaces == 1))
		{
			ft_putstr_fd("error with spaces\n", 2);
		   	exit (84);
		}
		else
		{
			ft_strdel(&line);
			spaces = 0;
		}
	}
	if (line && (ft_strcmp(line, "") == 0) && (get_next_line(fd, &line) == 0))
	{
		ft_putstr_fd("Spaces at the EOF\n", 2);
		exit(84);
	}
	close(fd);
	return (0);
}
