#!/bin/sh

make re -C ../../
clang -Wall -Werror -Wextra -L ../../ -lftprintf -I ../../includes/ dumb_main.c -o dumb.out
