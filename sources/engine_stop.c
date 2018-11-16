/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:53:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 12:49:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	engine_stop(t_engine data)
{
	write(1, "A\n", 2);
	// free(data.window.surface->userdata);
	write(1, "B\n", 2);
	// SDL_FreeSurface(data.window.surface);
	write(1, "C\n", 2);
	SDL_DestroyRenderer(data.window.renderer);
	write(1, "D\n", 2);
	SDL_DestroyWindow(data.window.ptr);
	write(1, "E\n", 2);
	SDL_Quit();
	write(1, "F\n", 2);
	delete_data(data);
	write(1, "G\n", 2);
	delete_textures(data);
	write(1, "H\n", 2);
}
