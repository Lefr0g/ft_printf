#!/bin/sh

echo -e "\n\033[033m>>> Compiling sizeof.c :\033[0m\n"
#make re -C ../../
clang -Wall -Werror -Wextra sizeof.c -o sizeof.out
#	-I ../../includes/ -L ../../ -lftprintf \
echo -e "\n\033[033m>>> Running sizeof.out :\033[0m\n"
./sizeof.out
