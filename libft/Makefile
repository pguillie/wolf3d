# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:46:38 by pguillie          #+#    #+#              #
#    Updated: 2018/11/16 01:08:15 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
WFLAGS = -Wall -Werror -Wextra
CFLAGS = $(WFLAGS)

INCDIR = includes/
SRCDIR = sources/
OBJDIR = objects/

HEADERS = $(addprefix $(INCDIR), \
	get_next_line.h \
	libft.h \
)

SOURCES = $(addprefix $(SRCDIR), \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strndup.c \
	get_next_line.c \
)

OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	ar rc $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
