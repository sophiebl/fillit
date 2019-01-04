# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboucaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 13:36:39 by kboucaul          #+#    #+#              #
#    Updated: 2019/01/03 18:50:54 by sboulaao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = ./check_before.c \
		process.c \
		take_tetri.c \
		valid_file.c

OBJ = $(SRC:.c=.o)

INC = -I libft/includes -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) -o $@ $^

clean:
	@make clean -C libft/
		@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
