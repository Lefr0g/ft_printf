#!/bin/sh

gcc -Wall -Werror -Wextra -I ../../includes/ -L ../../ -lftprintf linkage.c -o linkage.out
