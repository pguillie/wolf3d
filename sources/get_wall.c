/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:39:15 by paul              #+#    #+#             */
/*   Updated: 2018/11/16 00:14:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static enum e_texture	get_wall_texture(struct s_map m, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || !(x < m.w) || !(y < m.h))
		return (T_DFLT);
	c = m.layout[y][x];
	if (c == 'b')
		return (T_BRICKS);
	else if (c == 'm')
		return (T_METAL);
	else if (c == 's')
		return (T_STONE);
	else if (c == 'w')
		return (T_WOOD);
	else
		return (T_DFLT);
}

static int				get_wall_x(struct s_player p, struct s_map m, t_wall *w,
	float a)
{
	int		x;
	int		dx;
	float	y;

	if (a == (float)M_PI_2 || a == -(float)M_PI_2)
		return (0);
	a = -a;
	x = (a > -M_PI_2 && a < M_PI_2 ? (int)ceilf(p.x) : (int)floorf(p.x));
	dx = (a > -M_PI_2 && a < M_PI_2 ? 1 : -1);
	w->dir = (a > -M_PI_2 && a < M_PI_2 ? WEST : EAST);
	y = p.y + (x - p.x) * tan(a);
	while (!(x < 1) && x < m.w && !(y < 0) && y < m.h
		&& m.layout[(int)y][(dx > 0 ? x : x - 1)] == ' ')
	{
		x += dx;
		y += dx * tan(a);
	}
	w->dist = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	w->texture = get_wall_texture(m, (dx > 0 ? x : x - 1), (int)y);
	w->col = (w->dir == WEST ? y - floorf(y) : ceilf(y) - y);
	return (1);
}

static int				get_wall_y(struct s_player p, struct s_map m, t_wall *w,
	float a)
{
	int		y;
	int		dy;
	float	x;

	if (a == 0 || a == (float)M_PI)
		return (0);
	a = -a;
	y = (a > 0 ? (int)ceilf(p.y) : (int)floorf(p.y));
	dy = (a > 0 ? 1 : -1);
	w->dir = (a > 0 ? NORTH : SOUTH);
	x = p.x + (y - p.y) / tan(a);
	while (!(x < 0) && x < m.w && !(y < 1) && y < m.h
		&& m.layout[(dy > 0 ? y : y - 1)][(int)x] == ' ')
	{
		y += dy;
		x += dy / tan(a);
	}
	w->dist = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	w->texture = get_wall_texture(m, (int)x, (dy > 0 ? y : y - 1));
	w->col = (w->dir == SOUTH ? x - floorf(x) : ceilf(x) - x);
	return (1);
}

float					get_wall(t_engine d, t_wall *w, float angle)
{
	t_wall	wx;
	t_wall	wy;
	int		success_x;
	int		success_y;

	if (angle < 0)
		angle = fmodf(angle - (float)M_PI, 2 * (float)M_PI)
			+ M_PI;
	else
		angle = fmodf(angle + (float)M_PI, 2 * (float)M_PI)
			- M_PI;
	success_x = get_wall_x(d.player, d.map, &wx, angle);
	success_y = get_wall_y(d.player, d.map, &wy, angle);
	if (!success_x)
		*w = wy;
	else if (!success_y)
		*w = wx;
	else
		*w = (wx.dist < wy.dist ? wx : wy);
	return (w->dist);
}
