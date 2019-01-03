/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:06:32 by kboucaul          #+#    #+#             */
/*   Updated: 2019/01/03 13:03:57 by kboucaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TETRI_H
# define _TETRI_H

int		take_tetri(const int fd);
int		check_size_tetri(char **tab, int nb_tetris);
int		check_spaces(int fd);
#endif
