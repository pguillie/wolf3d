/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:22:49 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 18:49:45 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	game_rotate(t_engine *data, t_rotate rotate)
{
	if (rotate == ROTATE_LEFT)
	{
		if (!(data->player.dir < M_PI))
			data->player.dir -= 2 * M_PI + M_PI / 100;
		else
		data->player.dir += M_PI / 100;
	}
	else if (rotate == ROTATE_RIGHT)
	{
		if (data->player.dir < -M_PI)
			data->player.dir += 2 * M_PI - M_PI / 100;
		else
			data->player.dir -= M_PI / 100;
	}
}
