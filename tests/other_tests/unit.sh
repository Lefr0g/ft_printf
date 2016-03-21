#!/bin/bash

# OS detection (Linux / OSX)
#
OS_NAME=`uname -s`
if [ $OS_NAME = "Linux" ]; then
	CC=gcc
elif [ $OS_NAME = "Darwin" ]; then
	CC=clang
fi
if [ $1 = "noflag" ]; then
	FLAGS=""
else
	FLAGS="-Wall -Werror -Wextra"
fi

if [ $CC = "gcc" ]; then
	FLAGS="$FLAGS -std=c99"
fi

echo -e "\n\033[033m>>> OS detected : $OS_NAME\033[0m"
echo -e "\n\033[033m>>> Running fclean.sh :\033[0m\n"
./fclean.sh
echo -e "\n\033[033m>>> Compiling unit.c :\033[0m\n"
make -C ../../
make -C ../../libft/
$CC -g $FLAGS -I ../../includes/ unit.c -L ../../libft -lft -L ../../ -lftprintf -o unit.out
echo -e "\n\033[033m>>> Running unit.out :\033[0m\n"
./unit.out
