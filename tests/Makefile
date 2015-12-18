# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 15:59:21 by amulin            #+#    #+#              #
#    Updated: 2015/12/18 15:59:32 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS detection (Linux / OSX)
#
OS_NAME = $(shell uname -s)
ifeq ($(OS_NAME),Linux)
	CC = gcc
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif

NAME = run_tests.out

FLAGS = -Wall -Werror -Wextra

ifeq ($(CC),gcc)
	FLAGS = $(FLAGS) -std=c99
endif

SRCS = pft_main.c pft_gears.c pft_interface.c pft_random_gens.c \
	   test_sequences.c pft_list.c pft_test_functions.c

SRCSDIR = sources/

SOURCES = $(addprefix $(SRCSDIR), $(SRCS))

HDRS = ft_printf_test.h

INCLUDIR = includes/

HEADERS = $(addprefix $(INCLUDIR), $(HDRS))

LIBINCLUDIR = ../includes/

LIBFT = ft

LIBFTPRINTF = ftprintf

LIBS = $(LIBFT) $(LIBFTPRINTF)

LIBFTWPREF = $(addprefix lib, $(LIBFT)) 

LIBFTPRINTFWPREF = $(addprefix lib, $(LIBFTPRINTF)) 

LIBFTWSUF = $(addsuffix .a, $(LIBFTWPREF))

LIBFTPRINTFWSUF = $(addsuffix .a, $(LIBFTPRINTFWPREF))

LIBFTDIR = ../libft/

LIBFTPRINTFDIR = ../

LIBDIRS = $(LIBFTDIR) $(LIBFTPRINTFDIR)

LIBFTWPATH = $(addprefix $(LIBFTDIR), $(LIBFTWSUF))

LIBFTPRINTFWPATH = $(addprefix $(LIBFTPRINTFDIR), $(LIBFTPRINTFWSUF))

LIBSWPATH = $(LIBFTWPATH) $(LIBFTPRINTFWPATH)

LIBDIRFLAGS = $(addprefix -L , $(LIBDIRS))

LIBAFLAGS = $(addprefix -l, $(LIBS))

.PHONY: all, clean, fclean, re

all : libs $(NAME)

$(NAME) : $(SOURCES) $(HEADERS) $(LIBSWPATH)
	$(CC) $(FLAGS) $(SOURCES) -I $(INCLUDIR) -I $(LIBINCLUDIR) \
		$(LIBDIRFLAGS) $(LIBAFLAGS) -o $(NAME)

libs :
	make -C ../
	make -C ../libft/

clean :
	make -C ../ fclean
	make -C ../libft/ fclean
	rm -f dummy.txt reference.txt

fclean : clean
	rm -f $(NAME)

re : fclean all
