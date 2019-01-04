/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:18:40 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/04 15:40:04 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char 	**gnl_to_line(char **tab, char *str, int nb_tetris)
{
	int 	i;
	int 	j;
	int 	k;
	char 	*tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = NULL;

	while (i < nb_tetris)
	{
		if (j == (int)ft_strlen(str))
			break ;
		while (k < 4)
		{
			tmp = ft_strdup(tab[i]);
			tab[i] = ft_strjoin(tmp, ft_strsub(str, j, 4));
			tmp = ft_strdup(tab[i]);
			tab[i] = ft_strjoin(tmp, "\n\0");
			free (tmp);
			k++;
			j = j + 4;
		}
		k = 0;
		i++;
	}
	tab[i] = "\0";
	return (tab);
}

char	**str_to_tab(char *str)
{
	char	**tab;
	int		nb_tetris;

	tab = my_alloc_tab(str, &nb_tetris);
	if (!tab)
		return (0);
	tab = gnl_to_line(tab, str, nb_tetris);
	return (tab);
}

char		index_into_letter(int i)
{
	char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (i < 0 && i > 25)
		exit (84);
	return (alph[i]);
}

char **put_letters(char **tab, int nb_tetris)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < nb_tetris)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = index_into_letter(i);
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

void	print_tab(char **tab, int nb_tetris)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (j == nb_tetris)
			break ;
		ft_putstr(tab[j]);
		ft_putchar('\n');
		j++;
	}
}

int		is_good_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '#') && (str[i] != '.') && (str[i] != '\0'))
			return (-1);
		i++;
	}
	return (0);
}

char	*my_get_line(const int *fd, char *line)
{
	int		readed;
	int		i;
	char 	*tmp;
	char 	*str;

	readed = 0;
	i = 0;
	str = (char *)malloc(sizeof(char*));
	if (str == NULL)
		exit (84);
	while ((readed = get_next_line(*fd, &line)) >= 0)
	{
		if (is_good_char(line) == -1)
		{
			free(line);
			exit (84);
		}
		if (line == NULL)
			i++;
		else if (ft_strcmp(line, "\n") || ft_strcmp(line, "\0"))
		{
			tmp = str;
			str = ft_strjoin(tmp, line);
			if (readed == 0)
				break ;
			free(tmp);
		}
		free(line);
	}
	return (str);
}
