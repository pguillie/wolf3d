/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:39:15 by paul              #+#    #+#             */
/*   Updated: 2018/10/23 16:31:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	get_wall_x(struct s_player p, struct s_map m, t_wall *w)
{
	int		x;
	int		dx;
	float	y;
	float	a;

	if (p.dir == (float)M_PI_2 || p.dir == -(float)M_PI_2)
		return (0);
	a = -p.dir;
	if (a > -M_PI_2 && a < M_PI_2)
	{
		x = (int)ceilf(p.x);
		dx = 1;
		w->dir = WEST;
	}
	else
	{
		x = (int)floorf(p.x);
		dx = -1;
		w->dir = EAST;
	}
	y = p.y + (x - p.x) * tan(a);
	while (!(x < 0) && x < m.w && !(y < 0) && y < m.h
		&& m.layout[(int)y][(dx > 0 ? x : x - 1)] == ' ')
	{
		x += dx;
		y += dx * tan(a);
	}
	w->dist = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	w->type = DEFAULT;
	return (1);
}

static int	get_wall_y(struct s_player p, struct s_map m, t_wall *w)
{
	int		y;
	int		dy;
	float	x;
	float	a;

	if (p.dir == 0 || p.dir == (float)M_PI)
		return (0);
	a = -p.dir;
	if (a > 0)
	{
		y = (int)ceilf(p.y);
		dy = 1;
		w->dir = NORTH;
	}
	else
	{
		y = (int)floorf(p.y);
		dy = -1;
		w->dir = SOUTH;
	}
	x = p.x + (y - p.y) / tan(a);
	while (!(x < 0) && x < m.w && !(y < 0) && y < m.h
		&& m.layout[(dy > 0 ? y : y - 1)][(int)x] == ' ')
	{
		y += dy;
		x += dy / tan(a);
	}
	w->dist = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	w->type = DEFAULT;
	return (1);
}

float		get_wall(t_engine d, t_wall *w)
{
	t_wall	wx;
	t_wall	wy;
	int		success_x;
	int		success_y;

	if (d.player.dir < 0)
		d.player.dir = fmodf(d.player.dir - (float)M_PI, 2 * (float)M_PI) + M_PI;
	else
		d.player.dir = fmodf(d.player.dir + (float)M_PI, 2 * (float)M_PI) - M_PI;
	success_x = get_wall_x(d.player, d.map, &wx);
	success_y = get_wall_y(d.player, d.map, &wy);
	if (!success_x)
		*w = wy;
	else if (!success_y)
		*w = wx;
	else
		*w = (wx.dist < wy.dist ? wx : wy);
	return (w->dist);
}
