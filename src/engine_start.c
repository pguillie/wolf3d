/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:25:31 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 12:00:28 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	engine_sdl(t_engine data)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		delete_data(data);
		return (-1);
	}
	return (0);
}

static int	engine_window(t_engine *data)
{
	data->window.w = WIN_WIDTH;
	data->window.h = WIN_HEIGHT;
	data->window.ptr = SDL_CreateWindow(
		"Wolf3D",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		data->window.w,
		data->window.h,
		0
	);
	if (data->window.ptr == NULL)
	{
		SDL_Quit();
		delete_data(*data);
		return (-1);
	}
	return (0);
}

static int	engine_renderer(t_engine *data)
{
	data->window.renderer = SDL_CreateRenderer(data->window.ptr, -1, 0);
	if (data->window.renderer == NULL)
	{
		SDL_DestroyWindow(data->window.ptr);
		SDL_Quit();
		delete_data(*data);
		return (-1);
	}
	return (0);
}

t_error		engine_start(t_engine *data, const char *data_file)
{
	t_error	err;

	if ((err = read_data(data_file, data)))
		return (err);
	if (engine_sdl(*data) < 0)
		return (ESDLINIT);
	if (engine_window(data) < 0)
		return (ESDLWINDOW);
	if (engine_renderer(data) < 0)
		return (ESDLRENDERER);
	return (ENONE);
}
