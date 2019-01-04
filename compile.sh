make -C libft/ fclean && make -C libft/
clang -g -Wall -Wextra -Werror -I libft/includes -c ./srcs/check_before.c ./srcs/process.c ./srcs/solver.c ./srcs/take_tetri.c ./srcs/valid_file.c
clang -g -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -g -o Fillit main.o -I libft/includes -L libft/ -lft
