/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 18:30:15 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		game_event(t_engine *data)
{
	SDL_Event	event;

	(void)data;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_w)
				game_move(data, MOVE_UP);
			else if (event.key.keysym.sym == SDLK_s)
				game_move(data, MOVE_DOWN);
			else if (event.key.keysym.sym == SDLK_a)
				game_move(data, MOVE_LEFT);
			else if (event.key.keysym.sym == SDLK_d)
				game_move(data, MOVE_RIGHT);
			else if (event.key.keysym.sym == SDLK_LEFT)
				game_rotate(data, ROTATE_LEFT);
			else if (event.key.keysym.sym == SDLK_RIGHT)
				game_rotate(data, ROTATE_RIGHT);
			else if (event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
		}
		else if (event.type == SDL_QUIT)
			return (0);
	}
	return (1);
}
