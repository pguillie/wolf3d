/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:17:37 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 20:24:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_move(t_engine *data, float angle)
{
	float	x;
	float	y;
	float	dist;

	dist = 0.1;
	angle += data->player.dir;
	x = data->player.x + cos(angle) * dist;
	y = data->player.y - sin(angle) * dist;
	/* find something clean */
	// if (x > 0.1 && x < data->map.w - 0.1
	// 	&& data->map.layout[(int)data->player.y][(int)x] == ' '
	// 	&& data->map.layout[(int)(data->player.y - 0.1)][(int)x] == ' '
	// 	&& data->map.layout[(int)(data->player.y + 0.1)][(int)x] == ' '
	// 	&& data->map.layout[(int)data->player.y][(int)(x - 0.1)] == ' '
	// 	&& data->map.layout[(int)data->player.y][(int)(x + 0.1)] == ' ')
	// 	data->player.x = x;
	// if (y > 0.1 && y < data->map.h - 0.1
	// 	&& data->map.layout[(int)y][(int)data->player.x] == ' '
	// 	&& data->map.layout[(int)y][(int)(data->player.x - 0.1)] == ' '
	// 	&& data->map.layout[(int)y][(int)(data->player.x + 0.1)] == ' '
	// 	&& data->map.layout[(int)(y - 0.1)][(int)data->player.x] == ' '
	// 	&& data->map.layout[(int)(y + 0.1)][(int)data->player.x] == ' ')
	// 	data->player.y = y;
	if (x > 0 && x < data->map.w
		&& data->map.layout[(int)data->player.y][(int)x] == ' ')
		data->player.x = x;
	if (y > 0 && y < data->map.h
		&& data->map.layout[(int)y][(int)data->player.x] == ' ')
		data->player.y = y;
}
