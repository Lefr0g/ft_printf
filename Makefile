# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/10 17:35:06 by amulin            #+#    #+#              #
#    Updated: 2016/03/24 14:30:02 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# *************************** #
# OS detection (Linux / OSX)

OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME),Linux)
	CC = gcc
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif
# *************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

ifeq ($(CC),gcc)
	FLAGS += -std=c99
endif

PRINTHDRS = ft_printf.h

PRINTINCLUDIR = includes/

PRINTHEADERS = $(addprefix $(PRINTINCLUDIR), $(PRINTHDRS))

PRINTSRCS = ft_printf.c ftpf_init.c \
			ftpf_lenmods_signed.c ftpf_lenmods_unsigned.c \
			ftpf_lenmods_text.c ftpf_lenmods_xp.c \
			ftpf_flags.c ftpf_output_rules.c \
			ftpf_conversions_text.c ftpf_conversions_signed.c \
			ftpf_conversions_unsigned.c ftpf_conversions_bonus.c \
			ftpf_directives.c

PRINTSRCDIR = sources/

PRINTSOURCES = $(addprefix $(PRINTSRCDIR), $(PRINTSRCS))

PRINTOBJECTS = $(subst .c,.o, $(PRINTSRCS))

LIBFTHDRS = libft.h

LIBFTINCLUDIR = libft/includes/

LIBFTHEADERS = $(addprefix $(LIBFTINCLUDIR), $(LIBFTHDRS))

LIBFTSRCS = ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar.c ft_putendl.c \
			ft_putendl_fd.c ft_putchar_fd.c \
			ft_putstr.c ft_putnbr.c ft_strcmp.c ft_strdup.c ft_strlen.c \
			ft_strnequ.c ft_strncmp.c \
			ft_isascii.c ft_isprint.c ft_strcpy.c ft_strnew.c ft_memalloc.c \
			ft_bzero.c ft_memset.c ft_strchr.c ft_strncpy.c ft_memmove.c \
			ft_memdel.c \
			ft_memcpy.c ft_isalpha.c ft_strdel.c \
			ft_uni_to_utf8.c ft_putwchar.c ft_putwstr.c ft_wstr_memsize.c \
			ft_wchar_utf8len.c ft_wstr_utf8len.c ft_wcslen.c ft_wcsncpy.c \
			ft_utf8ncpy.c \
			ft_getmax.c ft_itoa_ll.c ft_itoa_ull.c ft_putnbr_ll.c \
			ft_putnbr_ull.c ft_puthex_ull.c ft_putoctal.c \
			ft_abs.c ft_abs_ll.c ft_putbin.c \

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
	$(CC) -g $(FLAGS) -c $(SOURCES) -I $(PRINTINCLUDIR) -I $(LIBFTINCLUDIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
