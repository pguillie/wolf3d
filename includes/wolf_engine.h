/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:47:06 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/20 12:29:20 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_ENGINE_H
# define WOLF_ENGINE_H

enum wdir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef enum wdir e_wdir;

enum wtype
{
	NONE
};

struct s_map
{
	int		x;
	int		y;
	char	**layout;
};

struct s_player
{
	float	x;
	float	y;
	float	dir;
	int		fov;
};

struct s_wall
{
	float		dist;
	enum wdir	dir;
	enum wtype	type;
};


struct s_engine
{
	struct s_map	map;
	struct s_player	player;
};

typedef struct s_map t_map; //
typedef struct s_player t_player; //
typedef struct s_wall t_wall; //
typedef struct s_engine t_engine;

#endif
