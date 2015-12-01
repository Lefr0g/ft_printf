#!/bin/bash

# OS detection (Linux / OSX)
#
OS_NAME=`uname -s`
if [ $OS_NAME = "Linux" ]; then
	CC=gcc
elif [ $OS_NAME = "Darwin" ]; then
	CC=clang
fi

echo -e "\n\033[033m>>> Compiling unit.c :\033[0m\n"
make -C ../../
make -C ../../libft/
$CC -Wall -Werror -Wextra -I ../../includes/ unit.c -L ../../libft -lft -L ../../ -lftprintf -o unit.out
echo -e "\n\033[033m>>> Running unit.out :\033[0m\n"
./unit.out
