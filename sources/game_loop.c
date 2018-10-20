/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:08:31 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/20 18:13:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		game_loop(t_engine data)
{
	SDL_Window *win;

	SDL_Init(SDL_INIT_VIDEO); //

	win = SDL_CreateWindow("Wolf3D",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		0);

	if (win == NULL)
		printf("FAILED to create window\n");

	t_wall w;
	printf("%f\n", get_wall(data.player, data.map, &w));

	SDL_Delay(5000);

	SDL_DestroyWindow(win);

    SDL_Quit();
	return (0);
}
