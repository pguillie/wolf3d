/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:55:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 01:11:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_column(t_engine data, int column)
{
	t_wall	wall;
	int		height;
	int		margin;
	float	angle;

	angle = data.player.dir + data.window.fov / 2
		- column * data.window.fov / data.window.w;
	angle = fmodf(angle + 2 * M_PI, 2 * M_PI);
	get_wall(data, &wall, angle);
	wall.dist *= cos(data.player.dir - angle);
	height = data.window.real_h / wall.dist;
	margin = (data.window.h - height) / 2;
	// render_wall(data, wall, margin, height, column, angle);
	if (margin > 0)
	{
		render_sky(data, margin, column, angle);
		render_floor(data, margin + height, column);
	}
}
