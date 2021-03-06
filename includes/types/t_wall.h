/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wall.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:09:02 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 22:29:02 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WALL_H
# define T_WALL_H

# include "types/t_texture.h"

enum	e_wdir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

struct	s_wall
{
	float			dist;
	float			col;
	enum e_wdir		dir;
	enum e_texture	texture;
};

typedef struct s_wall	t_wall;

#endif
