/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:17:37 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 22:54:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_move(t_engine *data, float angle)
{
	float	x;
	float	y;
	float	dist;

	dist = 0.2;
	angle += data->player.dir;
	x = data->player.x + cos(angle) * dist;
	y = data->player.y - sin(angle) * dist;
	if (x > 0 && x < data->map.w
		&& data->map.layout[(int)data->player.y][(int)x] == ' ')
		data->player.x = x;
	if (y > 0 && y < data->map.h
		&& data->map.layout[(int)y][(int)data->player.x] == ' ')
		data->player.y = y;
}
