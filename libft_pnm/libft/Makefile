# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 11:31:02 by pguillie          #+#    #+#              #
#    Updated: 2018/11/07 21:32:26 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
AROPT = -rcs

CC = gcc
WFLAGS = -Wall -Werror -Wextra
CFLAGS = $(WFLAGS)

INCDIR = includes/
SRCDIR = sources/
OBJDIR = objects/

HEADERS = $(addprefix $(INCDIR), \
	libft.h \
)

SOURCES = $(addprefix $(SRCDIR), \
	ft_isdigit.c \
	ft_isspace.c \
	ft_memcpy.c \
	ft_putnbr_fd.c \
	ft_strlen.c \
)

OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	$(AR) $(AROPT) $(NAME) $(OBJECTS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
