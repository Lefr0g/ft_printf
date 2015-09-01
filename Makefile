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

PRINTHDRS = ft_printf.h

PRINTINCLUDIR = includes/

PRINTHEADERS = $(addprefix $(PRINTINCLUDIR), $(PRINTHDRS))

PRINTSRCS = ft_printf.c ft_puthex.c ft_puthex_ull.c ft_putnbr_ull.c \
			ft_putoctal.c ft_printf_init.c ft_itoa_ull.c

PRINTSRCDIR = sources/

PRINTSOURCES = $(addprefix $(PRINTSRCDIR), $(PRINTSRCS))

PRINTOBJECTS = $(subst .c,.o, $(PRINTSRCS))

LIBFTHDRS = libft.h

LIBFTINCLUDIR = libft/includes/

LIBFTHEADERS = $(addprefix $(LIBFTINCLUDIR), $(LIBFTHDRS))

LIBFTSRCS = ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar.c ft_putendl.c \
			ft_putstr.c ft_putnbr.c ft_strcmp.c ft_strdup.c ft_strlen.c \
			ft_isascii.c ft_isprint.c ft_strcpy.c ft_strnew.c ft_memalloc.c \
			ft_bzero.c ft_memset.c ft_strchr.c ft_strncpy.c ft_memmove.c \
			ft_memcpy.c

LIBFTSRCDIR = libft/

LIBFTSOURCES = $(addprefix $(LIBFTSRCDIR), $(LIBFTSRCS))

LIBFTOBJECTS = $(subst .c,.o, $(LIBFTSRCS))

SOURCES = $(PRINTSOURCES) $(LIBFTSOURCES)

OBJECTS = $(PRINTOBJECTS) $(LIBFTOBJECTS)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(HEADERS) $(LIBFT)
	clang $(FLAGS) -c $(SOURCES) -I $(PRINTINCLUDIR) -I $(LIBFTINCLUDIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
