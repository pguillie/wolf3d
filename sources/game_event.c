/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 22:08:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	game_set_action(SDL_Event event, t_engine *data)
{
	if (event.key.keysym.sym == SDLK_w)
		data->player.move[MOVE_UP] = 1;
	else if (event.key.keysym.sym == SDLK_s)
		data->player.move[MOVE_DOWN] = 1;
	else if (event.key.keysym.sym == SDLK_a)
		data->player.move[MOVE_LEFT] = 1;
	else if (event.key.keysym.sym == SDLK_d)
		data->player.move[MOVE_RIGHT] = 1;
	else if (event.key.keysym.sym == SDLK_LEFT)
		data->player.rotate[ROTATE_LEFT] = 1;
	else if (event.key.keysym.sym == SDLK_RIGHT)
		data->player.rotate[ROTATE_RIGHT] = 1;
}

static void	game_unset_action(SDL_Event event, t_engine *data)
{
	if (event.key.keysym.sym == SDLK_w)
		data->player.move[MOVE_UP] = 0;
	else if (event.key.keysym.sym == SDLK_s)
		data->player.move[MOVE_DOWN] = 0;
	else if (event.key.keysym.sym == SDLK_a)
		data->player.move[MOVE_LEFT] = 0;
	else if (event.key.keysym.sym == SDLK_d)
		data->player.move[MOVE_RIGHT] = 0;
	else if (event.key.keysym.sym == SDLK_LEFT)
		data->player.rotate[ROTATE_LEFT] = 0;
	else if (event.key.keysym.sym == SDLK_RIGHT)
		data->player.rotate[ROTATE_RIGHT] = 0;
}

static int	engine_resize_window(t_engine *data, int w, int h)
{
	data->window.w = w;
	data->window.h = h;
	data->window.fov = 2 * atan(0.5) * data->window.w / data->window.h;
	if (data->window.fov * 180 / M_PI > FOV_MAX)
	{
		data->window.fov = FOV_MAX * M_PI / 180;
		data->window.real_h = 2 * atan(0.5) * data->window.w / data->window.fov;
	}
	else
		data->window.real_h = data->window.h;
	free(data->window.surface->userdata);
	SDL_FreeSurface(data->window.surface);
	data->window.surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	if (data->window.surface)
		data->window.surface->userdata = malloc(
			data->window.surface->h * data->window.surface->pitch);
	else
		return (-1);
	if (data->window.surface->userdata == NULL)
	{
		SDL_FreeSurface(data->window.surface);
		return (-1);
	}
	return (0);
}

static void	game_event_key(SDL_Event event, t_engine *data)
{
	int	quality;

	if (event.key.keysym.sym == SDLK_1)
		quality = 1;
	else if (event.key.keysym.sym == SDLK_2)
		quality = 2;
	else if (event.key.keysym.sym == SDLK_3)
		quality = 3;
	else
	{
		game_set_action(event, data);
		return ;
	}
	if (quality != data->quality)
	{
		data->quality = quality;
		delete_textures(*data);
		engine_load_textures(data);
	}
}

int			game_event(t_engine *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
			game_event_key(event, data);
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			else
				game_unset_action(event, data);
		}
		else if (event.type == SDL_WINDOWEVENT)
		{
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				if (engine_resize_window(data, event.window.data1,
					event.window.data2))
					return (-1);
		}
		else if (event.type == SDL_QUIT)
			return (0);
	}
	return (1);
}
