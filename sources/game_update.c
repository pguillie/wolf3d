/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:50:43 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/23 17:56:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_update(t_engine *data)
{
	if (data->player.move[MOVE_UP])
		game_move(data, 0);
	if (data->player.move[MOVE_DOWN])
		game_move(data, M_PI);
	if (data->player.move[MOVE_RIGHT])
		game_move(data, -M_PI_2);
	if (data->player.move[MOVE_LEFT])
		game_move(data, M_PI_2);
	if (data->player.rotate[ROTATE_LEFT])
		game_rotate(data, 1);
	if (data->player.rotate[ROTATE_RIGHT])
		game_rotate(data, -1);
}
