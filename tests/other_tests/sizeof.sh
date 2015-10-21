#!/bin/sh

echo "\n\033[033m>>> Compiling sizeof.c :\033[0m\n"
make re -C ../../
clang -Wall -Werror -Wextra sizeof.c \
	-I ../../includes/ -L ../../ -lftprintf \
	-o sizeof.out
echo "\n\033[033m>>> Running sizeof.out :\033[0m\n"
./sizeof.out
