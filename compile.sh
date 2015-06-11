#!/bin/sh

make  fclean
make -C libft/ fclean
make
make -C libft/
clang -Wall -Werror -Wextra main.c -L . -lftprintf \
	-I includes/ -L libft/ -lft -I libft/includes/ -o a.out
