/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_before.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:17:32 by kboucaul          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_tetris_nb_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 4)
		{
			if (ft_strcmp(line, "") != 0)
			{
				ft_putstr_fd("error\n", 2);
				exit(84);
			}
			i = 0;
		}
		else
			i++;
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

int			check_spaces(int fd)
{
	char	*line;
	int		spaces;

	spaces = 0;
	get_next_line(fd, &line);
	if (ft_strcmp(line, "") == 0)
	{
		ft_putstr_fd("error", 2);
		exit(84);
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_strcmp(line, "") == 0) && (spaces == 0))
			spaces = 1;
		else if ((ft_strcmp(line, "") == 0) && (spaces == 1))
		{
			ft_putstr_fd("error", 2);
			exit(84);
		}
		else
		{
			ft_strdel(&line);
			spaces = 0;
		}
	}
	if (line && (ft_strcmp(line, "") == 0) && (get_next_line(fd, &line) == 0))
	{
		ft_putstr_fd("error", 2);
		exit(84);
	}
	close(fd);
	return (0);
}
