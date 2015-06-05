#!/bin/sh

make -C libft/ fclean
make -C libft/
clang -Wall -Werror -Wextra -I libft/includes/ ft_printf.c -c -std=c99
clang -Wall -Werror -Wextra -I libft/includes/ main.c -L libft/ -lft -o maintest
