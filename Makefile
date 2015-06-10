# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/10 17:35:06 by amulin            #+#    #+#              #
#    Updated: 2015/06/10 19:48:18 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

HDRS = ft_printf.h

INCLUDIR = includes/

HEADERS = $(addprefix $(INCLUDIR), $(HDRS))

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

OBJECTS = $(subst .c,.o, $(SRCS))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(HEADERS)
	clang $(FLAGS) -c $(SOURCES) -I $(INCLUDIR)

$(LIBFT):
	make -C libft/ all

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
