# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:46:38 by pguillie          #+#    #+#              #
#    Updated: 2018/10/25 16:20:02 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc
WFLAGS = -Wall -Werror -Wextra
CFLAGS = $(WFLAGS)

LMATH = -lm
# SDL = SDL2/sources/SDL2.a?
ifeq ($(shell uname), Darwin)
	LSDL = /Library/Frameworks/SDL2.framework/SDL2
else
	LSDL = -lSDL2
endif
LIBFT = libft/libft.a
LFT = -Llibft -lft

INCDIR = inc/
SRCDIR = src/
OBJDIR = obj/

HEADERS = $(addprefix $(INCDIR), \
	wolf3d.h \
	types/t_coord.h \
	types/t_engine.h \
	types/t_error.h \
	types/t_move.h \
	types/t_rotate.h \
	types/t_wall.h \
	libft/get_next_line.h \
	libft/libft.h \
)

SOURCES = $(addprefix $(SRCDIR), \
	delete_data.c \
	engine_start.c \
	engine_stop.c \
	ft_perror.c \
	game_event.c \
	game_move.c \
	game_rotate.c \
	game_update.c \
	game.c \
	get_wall.c \
	main.c \
	read_data.c \
	render_image.c \
)

OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LMATH) $(LSDL) $(LFT)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make -C $(dir $(LIBFT)) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	rm -f $(NAME)

re: fclean all
