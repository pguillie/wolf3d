/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:18 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/23 17:55:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_error	read_data(const char *file, t_engine *data)
{
	(void)file;
	data->map.layout = (char**)malloc(6 * sizeof(char *));
	data->map.layout[0] = strdup("wwwwwwwwww");
	data->map.layout[1] = strdup("w        w");
	data->map.layout[2] = strdup("ww       w");
	data->map.layout[3] = strdup("w        w");
	data->map.layout[4] = strdup("w       ww");
	data->map.layout[5] = strdup("wwwwwwwwww");
	data->map.w = 10;
	data->map.h = 6;
	data->player.x = 5.5;
	data->player.y = 3.5;
	data->player.dir = 0;
	data->player.fov = 60;
	data->player.speed = 10;
	memset(data->player.move, 0, 4 * sizeof(t_move));
	memset(data->player.rotate, 0, 2 * sizeof(t_rotate));
	return (0);
}
