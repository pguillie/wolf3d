/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:08:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/23 16:45:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENGINE_H
# define T_ENGINE_H

# include "types/t_move.h"
# include "types/t_rotate.h"

# define SPEED_MAX 100

struct	s_player
{
	float		x;
	float		y;
	float		dir;
	int			fov;
	int			speed;
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
};

struct	s_engine
{
	struct s_player	player;
	struct s_map	map;
	struct s_window	window;
};

typedef struct s_engine	t_engine;

#endif
