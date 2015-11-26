#!/bin/sh

echo -e "\n\033[033m>>> Compiling dumb.c :\033[0m\n"
make -C ../../
make -C ../../libft/
gcc -Wall -Werror -Wextra -I ../../includes unit.c -L ../../libft -lft -L ../../ -lftprintf -o unit.out
echo -e "\n\033[033m>>> Running dumb.out :\033[0m\n"
./unit.out
