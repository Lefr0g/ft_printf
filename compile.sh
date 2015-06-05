#!/bin/sh

make -C libft/ fclean
rm *.o
make -C libft/
clang -Wall -Werror -Wextra -I libft/includes/ ft_printf.c -c -std=c99
clang -Wall -Werror -Wextra -I libft/includes/ main.c -c
clang -Wall -Werror -Wextra main.o ft_printf.o -L libft/ -lft
