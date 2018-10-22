/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:08:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 10:57:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENGINE_H
# define T_ENGINE_H

struct	s_player
{
	float	x;
	float	y;
	float	dir;
	int		fov;
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
