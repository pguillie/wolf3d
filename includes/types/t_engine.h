/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:08:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/13 16:26:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENGINE_H
# define T_ENGINE_H

# include "types/t_move.h"
# include "types/t_rotate.h"
# include "types/t_texture.h"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

// # define WIN_WIDTH 1000
// # define WIN_HEIGHT 1000

# define FOV_MIN 40
# define FOV_MAX 100

# define UPDATE_DELAY 10000 //

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
	int				w;
	int				h;
	int				calc_h;
	float			fov;
};

struct	s_engine
{
	struct s_player	player;
	struct s_map	map;
	struct s_window	window;
	uint8_t			*textures[4];
};

typedef struct s_engine	t_engine;

#endif
