#!/bin/sh

echo "\n\033[033m>>> Compiling compare.c :\033[0m\n"
make re -C ../../
#clang -Wall -Wextra -Werror -I ../../includes/ -L ../../ -lftprintf compare.c \
clang -I ../../includes/ -L ../../ -lftprintf compare.c \
	-o compare.out
echo "\n\033[033m>>> Running compare.out :\033[0m\n"
./compare.out
