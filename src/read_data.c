/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:18 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 18:36:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_error	read_data(const char *file, t_engine *data)
{
	(void)file;
	data->map.layout = (char**)malloc(7 * sizeof(char *));
	data->map.layout[0] = strdup("wwwwwwwwww");
	data->map.layout[1] = strdup("w        w");
	data->map.layout[2] = strdup("w        w");
	data->map.layout[3] = strdup("w        w");
	data->map.layout[4] = strdup("w         ");
	data->map.layout[5] = strdup("wwwwwww   ");
	data->map.w = 10;
	data->map.h = 6;
	data->player.x = 5.5;
	data->player.y = 3.5;
	data->player.dir = 0;
	data->player.fov = 60;
	return (0);
}
