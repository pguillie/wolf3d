# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paul <paul@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:46:38 by pguillie          #+#    #+#              #
#    Updated: 2018/10/18 20:33:10 by paul             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d
CC		= gcc
LMATH	= -lm
WFLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(WFLAGS)

INCDIR	= includes/
SRCDIR	= sources/
OBJDIR	= objects/

HEADERS	= $(addprefix $(INCDIR), \
	wolf3d.h \
	wolf_engine.h \
)

SOURCES	= $(addprefix $(SRCDIR), \
	main.c \
)

OBJECTS	= $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(LMATH) -o $@ $(OBJECTS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
