#!/bin/sh

make re -C ../../
clang -Wall -Werror -Wextra -I ../../includes/ -L ../../ -lftprintf short_tests.c -o short.out
