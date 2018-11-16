/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:25:31 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 00:13:52 by pguillie         ###   ########.fr       */
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
		SDL_WINDOW_RESIZABLE
);
	if (data->window.ptr == NULL)
	{
		SDL_Quit();
		delete_data(*data);
		return (-1);
	}
	data->window.fov = 2 * atan(0.5) * data->window.w / data->window.h;
	if (data->window.fov * 180 / M_PI > FOV_MAX)
	{
		data->window.fov = FOV_MAX * M_PI / 180;
		data->window.real_h = 2 * atan(0.5) * data->window.w / data->window.fov;
	}
	else
		data->window.real_h = data->window.h;
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

static int	engine_surface(t_engine *data)
{
	SDL_Surface	*s;

	s = SDL_CreateRGBSurface(0, data->window.w, data->window.h, 32, 0, 0, 0, 0);
	if (s)
		s->userdata = malloc(s->h * s->pitch);
	if (s == NULL || s->userdata == NULL)
	{
		if (s)
			SDL_FreeSurface(s);
		SDL_DestroyRenderer(data->window.renderer);
		SDL_DestroyWindow(data->window.ptr);
		SDL_Quit();
		delete_data(*data);
		return (-1);
	}
	data->window.surface = s;
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
	if (engine_surface(data) < 0)
		return (ESDLSURFACE);
	if (engine_load_textures(data))
		ft_perror(ELOADTEXTURE);
	return (ENONE);
}
