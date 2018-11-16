/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 00:41:52 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 01:09:33 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_floor(t_engine data, int begin, int column)
{
	while (begin < data.window.h)
	{
		*(Uint32 *)(data.window.surface->userdata
			+ begin * data.window.surface->pitch
			+ column * data.window.surface->format->BytesPerPixel) =
				SDL_MapRGB(data.window.surface->format,
				42, 42, 42);
		begin++;
	}
}
