#!/bin/sh

echo "\n\033[033m>>> Compiling sizeof.c :\033[0m\n"
make re -C ../../
clang -Wall -Werror -Wextra -I ../../includes/ -L ../../ -lftprintf sizeof.c \
	-o sizeof.out
echo "\n\033[033m>>> Running sizeof.out :\033[0m\n"
./sizeof.out
