/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/28 19:31:23 by pguillie         ###   ########.fr       */
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

static void	engine_resize_window(SDL_Event event, t_engine *data)
{
	data->window.w = event.window.data1;
	data->window.h = event.window.data2;
}

int			game_event(t_engine *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
			game_set_action(event, data);
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			else
				game_unset_action(event, data);
		}
		else if (event.type == SDL_WINDOWEVENT)
		{
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED
				|| event.window.event == SDL_WINDOWEVENT_RESIZED)
				engine_resize_window(event, data);
		}
		else if (event.type == SDL_QUIT)
			return (0);

		/////////
		else if (event.type == SDL_WINDOWEVENT) {
			switch (event.window.event) {
			case SDL_WINDOWEVENT_SHOWN:
				SDL_Log("Window %d shown", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				SDL_Log("Window %d hidden", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_EXPOSED:
				SDL_Log("Window %d exposed", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_MOVED:
				SDL_Log("Window %d moved to %d,%d",
						event.window.windowID, event.window.data1,
						event.window.data2);
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_Log("Window %d resized to %dx%d",
						event.window.windowID, event.window.data1,
						event.window.data2);
				break;
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				SDL_Log("Window %d size changed to %dx%d",
						event.window.windowID, event.window.data1,
						event.window.data2);
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				SDL_Log("Window %d minimized", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				SDL_Log("Window %d maximized", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_RESTORED:
				SDL_Log("Window %d restored", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_ENTER:
				SDL_Log("Mouse entered window %d",
						event.window.windowID);
				break;
			case SDL_WINDOWEVENT_LEAVE:
				SDL_Log("Mouse left window %d", event.window.windowID);
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				SDL_Log("Window %d gained keyboard focus",
						event.window.windowID);
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				SDL_Log("Window %d lost keyboard focus",
						event.window.windowID);
				break;
			case SDL_WINDOWEVENT_CLOSE:
				SDL_Log("Window %d closed", event.window.windowID);
				break;
			default:
				SDL_Log("Window %d got unknown event %d",
						event.window.windowID, event.window.event);
				break;
			}
		}

	}
	return (1);
}
