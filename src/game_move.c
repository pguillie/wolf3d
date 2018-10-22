/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:17:37 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 18:37:31 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_move(t_engine *data, t_move move)
{
	float	angle;

	if (move == MOVE_UP)
		angle = data->player.dir;
	if (move == MOVE_DOWN)
		angle = data->player.dir + M_PI;
	if (move == MOVE_RIGHT)
		angle = data->player.dir - M_PI_2;
	if (move == MOVE_LEFT)
		angle = data->player.dir + M_PI_2;
	data->player.x += cos(angle) / 10;
	data->player.y -= sin(angle) / 10;
}
