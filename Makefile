# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:46:38 by pguillie          #+#    #+#              #
#    Updated: 2018/10/20 18:12:52 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d
CC		= gcc
LMATH	= -lm
LSDL	= /Library/Frameworks/SDL2.framework/SDL2
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
	game_loop.c \
	get_wall.c \
	main.c \
)

OBJECTS	= $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(LMATH) $(LSDL) -o $@ $(OBJECTS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
