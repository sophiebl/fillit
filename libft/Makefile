# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboulaao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 17:19:49 by sboulaao          #+#    #+#              #
#    Updated: 2019/01/09 13:00:52 by sboulaao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

AR = ar rc

FLAGS = -Wall -Werror -Wextra

SRC = ./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memccpy.c \
		./ft_memmove.c \
		./ft_memcmp.c \
		./ft_memchr.c \
		./ft_atoi.c \
		./ft_itoa.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_strcat.c \
		./ft_strcmp.c \
		./ft_strncmp.c \
		./ft_strcpy.c \
		./ft_strncpy.c \
		./ft_strdup.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strncat.c \
		./ft_strstr.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strtrim.c \
		./ft_strnstr.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_isalnum.c \
		./ft_strnew.c \
		./ft_memdel.c \
		./ft_strdel.c \
		./ft_strclr.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strequ.c \
		./ft_strnequ.c \
		./ft_strsub.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_lstnew.c \
		./ft_lstdelone.c \
		./ft_lstdel.c \
		./ft_lstadd.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_strsplit.c \
		./ft_countw.c \
		./ft_append.c \
		./ft_size_word.c \
		./ft_strtolower.c \
		./ft_strtoupper.c \
		./ft_size_word.c \
		./ft_swap.c \
		./get_next_line.c \
		./ft_memalloc.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c  $< -o $@

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
