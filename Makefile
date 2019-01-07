# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 13:36:39 by kboucaul          #+#    #+#              #
#    Updated: 2019/01/07 13:52:03 by kboucaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fillit

SRCS		=		./srcs/main.c				\
					./srcs/check_before.c		\
					./srcs/check_form.c			\
					./srcs/process.c			\
					./srcs/take_tetri.c			\
					./srcs/valid_file.c

OBJS		=		$(SRCS:%.c=%.o)

CC			=		gcc

CFLAGS		+=		-Wall -Wextra -Werror -I ./include

LIB			=		-L./libft -lft

RM			=		rm -f

CLEAN		=		clean

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					make -C ./libft/
					$(CC) -o $(NAME) $(OBJS) $(LIB)

clean		:		
					$(RM) $(OBJS)
					make clean -C ./libft

fclean		:		clean
					$(RM) $(NAME)
					make fclean -C ./libft/

re			:		fclean	all
