/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_engine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:08:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/21 21:10:47 by pguillie         ###   ########.fr       */
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
	SDL_Window	*ptr;
	int			w;
	int			h;
};

struct	s_engine
{
	struct s_player	player;
	struct s_map	map;
	struct s_window	window;
};

typedef struct s_engine	t_engine;

#endif
