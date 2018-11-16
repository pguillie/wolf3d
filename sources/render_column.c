/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:55:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 22:07:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_column(t_engine data, int column)
{
	t_wall	wall;
	int		limits[2];
	float	angle;

	angle = data.player.dir + data.window.fov / 2
		- column * data.window.fov / data.window.w;
	angle = fmodf(angle + 2 * M_PI, 2 * M_PI);
	get_wall(data, &wall, angle);
	wall.dist *= cos(data.player.dir - angle);
	limits[1] = data.window.real_h / wall.dist;
	limits[0] = (data.window.h - limits[1]) / 2;
	render_wall(data, wall, limits, column);
	if (limits[0] > 0)
	{
		render_sky(data, limits[0], column, angle);
		render_floor(data, limits[0] + limits[1], column);
	}
}
