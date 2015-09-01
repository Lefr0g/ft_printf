#!/bin/sh

echo "\n\033[033m>>> Compiling dumb.c :\033[0m\n"
make re -C ../../
clang -Wall -Werror -Wextra -L ../../ -lftprintf -I ../../includes/ dumb.c -o dumb.out
echo "\n\033[033m>>> Running dumb.out :\033[0m\n"
./dumb.out
