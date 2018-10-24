/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wall.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:09:02 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/24 15:34:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WALL_H
# define T_WALL_H

enum	e_wdir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum	e_wtype
{
	WDEFAULT,
	WWOOD
};

struct	s_wall
{
	float			dist;
	enum e_wdir		dir;
	enum e_wtype	type;
};

typedef struct s_wall	t_wall;

#endif
