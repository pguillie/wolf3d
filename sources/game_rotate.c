/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:22:49 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/25 16:14:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_rotate(t_engine *data, int sign)
{
	float	rot;

	rot = sign * M_PI_4 / 10;
	data->player.dir += rot;
	if (!(data->player.dir + rot < (float)M_PI))
		data->player.dir -= 2 * (float)M_PI;
	else if (data->player.dir - rot < (float)-M_PI)
		data->player.dir += 2 * (float)M_PI;
}
