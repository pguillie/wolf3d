/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:08:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 22:53:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENGINE_H
# define T_ENGINE_H

# include "types/t_move.h"
# include "types/t_rotate.h"
# include "types/t_texture.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define FOV_MAX 100

# define UPDATE_DELAY 100000

# define THREAD_NB 16

struct	s_player
{
	float		x;
	float		y;
	float		dir;
	t_move		move[4];
	t_rotate	rotate[2];
};

struct	s_map
{
	int		w;
	int		h;
	char	**layout;
};

struct	s_window
{
	SDL_Window		*ptr;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	int				w;
	int				h;
	int				real_h;
	float			fov;
};

struct	s_engine
{
	struct s_player	player;
	struct s_map	map;
	struct s_window	window;
	uint8_t			*textures[NB_TEXTURE];
	uint8_t			*sky;
	int				quality;
};

typedef struct s_engine	t_engine;

struct	s_thread
{
	pthread_t	id;
	t_engine	data;
	int			begin;
	int			end;
};

typedef struct s_thread	t_thread;

#endif
