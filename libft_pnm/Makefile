# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 11:31:02 by pguillie          #+#    #+#              #
#    Updated: 2018/11/09 23:57:40 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft_pnm.a

AR := ar

CC := gcc
WFLAGS := -Wall -Werror -Wextra
CFLAGS = $(WFLAGS)

LIBFT := libft/libft.a

INCDIR := includes/
SRCDIR := sources/
OBJDIR := objects/
INCLUDES = -I$(INCDIR) \
	-I$(dir $(LIBFT))includes

HEADERS := $(addprefix $(INCDIR), \
	types/t_pnm.h \
	libft_pnm.h \
)

SOURCES := $(addprefix $(SRCDIR), \
	ft_pnm_alloc_row.c \
	ft_pnm_free_row.c \
	ft_pnm_dim.c \
	ft_pnm_plainformat.c \
	ft_pnm_maxval.c \
	ft_pnm_read_init.c \
	ft_pnm_read_pbm_row.c \
	ft_pnm_read_quit.c \
	ft_pnm_read_row.c \
	ft_pnm_type.c \
	ft_pnm_write_init.c \
	ft_pnm_write_pbm_row.c \
	ft_pnm_write_quit.c \
	ft_pnm_write_row.c \
)

OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBOBJ = $(addprefix $(OBJDIR), $(shell $(AR) t $(LIBFT) | grep .o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)
	cp $(LIBFT) $(OBJDIR)
	cd $(OBJDIR) && $(AR) x $(notdir $(LIBFT))
	$(AR) rs $@ $(LIBOBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C $(dir $(LIBFT))

clean:
	make -C $(dir $(LIBFT)) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	rm -f $(NAME)

re: fclean all
