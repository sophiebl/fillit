/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:27:24 by sboulaao          #+#    #+#             */
/*   Updated: 2019/01/11 13:43:07 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_tetri
{
	char				**cut_out_tetri;
	int					width;
	int					height;
	char				letter;
}						t_tetri;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_map
{
	char				**map;
	int					size;
}						t_map;

/*
**		Main.c
*/

void					print_solution(t_map *map);
int						main(int ac, char **av);

/*
**		Get_my_file
*/

char					**cut_the_tetri(char *str, t_point *coord_min,
						t_point *coord_max);
t_tetri					*get_tetri(char *str, char letter);
t_list					*read_tetri(int fd, char *letter);

/*
**		My_check_function
*/

int						check_counts(char *tetri, int rd);
int						check_link(char *tetri);
void					get_coord(char *tetri, t_point *coord_min,
						t_point *coord_max);

/*
**		My_alloc_ressources
*/

t_point					*value_to_point(int x, int y);
t_tetri					*value_to_tetri(char **cut_out_tetri,
						int width, int height, char letter);

/*
**		My_free_ressources
*/

void					free_tetris(t_tetri *tetri);
t_list					*free_list_tetris(t_list *list);
void					free_point(t_point **coord_min, t_point **coord_max);
void					free_map(t_map *map);
#endif
