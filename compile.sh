#!/bin/sh

make -C libft/ fclean
make -C libft/
gcc -Wall -Werror -Wextra -I libft/includes/ ft_printf.c -o test_ft_printf -std=c99
