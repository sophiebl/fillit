/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:06:32 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 15:23:34 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TETRI_H
# define _TETRI_H

int		take_tetri(const int fd);
int		check_size_tetri(char **tab, int nb_tetris);
int		check_spaces(int fd);
int		check_tetris_nb_lines(int fd);
char    **gnl_to_line(char **tab, char *str, int nb_tetris);
char    **str_to_tab(char *str);
char        index_into_letter(int i);
char **put_letters(char **tab, int nb_tetris);
void    print_tab(char **tab, int nb_tetris);
int     is_good_char(char *str);
char    *my_get_line(const int *fd, char *line);
char **my_alloc_tab(char *str, int *nb_tetris);
#endif
