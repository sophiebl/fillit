/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:27:24 by sboulaao          #+#    #+#             */
/*   Updated: 2019/01/09 13:38:53 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 6

#include "../libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct      s_point
{
	int             	x;
	int             	y;
}                   t_point;

typedef struct      t_tetri
{
	t_point		       	pos;
	char            	*shape;
	char             	lettre;
}                   tetri_lst;

int						get_next_line(const int fd, char **line);
int						take_tetri(const int fd);
int						check_size_tetri(char **tab, int nb_tetris);
int						check_spaces(int fd);
int						check_tetris_nb_lines(int fd);
char					**gnl_to_line(char **tab, char *str, int nb_tetris);
char					**str_to_tab(char *str);
char					index_into_letter(int i);
char					**put_letters(char **tab, int nb_tetris);
void					print_tab(char **tab, int nb_tetris);
int						is_good_char(char *str);
char					*my_get_line(const int *fd, char *line);
char					**my_alloc_tab(char *str, int *nb_tetris);
int						solve(char **tab, int nb_tetris);
int     				check_links(char *tab);
int     				check_form(char **tab, int index);

# endif			
