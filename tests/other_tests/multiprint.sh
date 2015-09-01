#!/bin/sh

echo "\n\033[033m>>> Compiling multiprint.c :\033[0m\n"
make -C ../../libft/ re
make -C ../../ re
clang -Wall -Werror -Wextra multiprint.c -L ../../ -lftprintf \
	-I ../../includes/ -L ../../libft/ -lft -I ../../libft/includes/ -o multiprint.out
echo "\n\033[033m>>> Running multiprint.out :\033[0m\n"
./multiprint.out
