# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 14:46:25 by abaker            #+#    #+#              #
#    Updated: 2021/09/07 17:16:52 by abaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
CC = gcc
FLAGS = -std=c99
CFLAGS = -Werror -Wall -Wextra -c -g

NAME = libft.a
SOURCES = ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c
BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
        ft_lstclear.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstlast.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_lstsize.c
HEADERS = libft.h
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECT): $(SRC)
	$(CC) $(FLAGS) $(CFLAGS) -o $(NAME) $(OBJECTS) $(HEADERS)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
		@rm -rf $(NAME)
		@echo "[INFO] Library [$(NAME) removed!"


#Re-make everything.
re:		fclean all

.PHONY:
	all clean fclean re
