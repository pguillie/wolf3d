/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:25:31 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/21 21:04:05 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_error	read_data(const char *file, t_engine *data)
{
	(void)file;
	data->map.layout = (char**)malloc(5 * sizeof(char *));
	data->map.layout[0] = strdup("11111");
	data->map.layout[1] = strdup("10001");
	data->map.layout[2] = strdup("10011");
	data->map.layout[3] = strdup("11111");
	data->map.layout[4] = strdup("11111");
	data->map.w = 5;
	data->map.h = 5;
	data->player.x = 2.5;
	data->player.y = 2.5;
	return (0);
}

t_error	engine_start(t_engine *data, const char *data_file)
{
	t_error	err;

	if ((err = read_data(data_file, data)))
		return (err);
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // free engine (delete_data)
		return (ESDLINIT);
	data->window.ptr = SDL_CreateWindow(
		"Wolf3D",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIN_WIDTH,
		WIN_HEIGHT,
		0
	);
	if (data->window.ptr == NULL)
	{
		SDL_Quit();
		return (ESDLWIN);
	}
	return (ENONE);
}
