# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 13:46:38 by pguillie          #+#    #+#              #
#    Updated: 2018/11/16 22:32:08 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

CC := gcc
WFLAGS := -Wall -Werror -Wextra
CFLAGS = $(WFLAGS) -fsanitize=address

LMATH := -lm
# SDL = SDL2/sources/SDL2.a?
ifeq ($(shell uname), Darwin)
	LSDL := /Library/Frameworks/SDL2.framework/SDL2
else
	LSDL := -lSDL2
endif

LIBFT_PNM := libft_pnm/libft_pnm.a
LFT_PNM := -Llibft_pnm -lft_pnm
LIBFT := libft/libft.a
LFT := -Llibft -lft

INCDIR := includes/
SRCDIR := sources/
OBJDIR := objects/

INCLUDES = -I$(INCDIR) \
	-I$(dir $(LIBFT))includes \
	-I$(dir $(LIBFT_PNM))includes

HEADERS = $(addprefix $(INCDIR), \
	wolf3d.h \
	types/t_coord.h \
	types/t_engine.h \
	types/t_error.h \
	types/t_move.h \
	types/t_rotate.h \
	types/t_texture.h \
	types/t_wall.h \
)

SOURCES = $(addprefix $(SRCDIR), \
	delete_data.c \
	delete_textures.c \
	engine_load_textures.c \
	engine_start.c \
	engine_stop.c \
	ft_perror.c \
	game_event.c \
	game_move.c \
	game_rotate.c \
	game_update.c \
	game.c \
	get_wall.c \
	load_texture.c \
	main.c \
	read_data.c \
	render_column.c \
	render_floor.c \
	render_image.c \
	render_sky.c \
	render_wall.c \
)

OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFT_PNM) $(OBJDIR) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LMATH) $(LSDL) $(LFT) $(LFT_PNM)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(LIBFT_PNM):
	make -C $(dir $(LIBFT_PNM))

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(LIBFT_PNM)) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(LIBFT_PNM)) fclean
	rm -f $(NAME)

re: fclean all
