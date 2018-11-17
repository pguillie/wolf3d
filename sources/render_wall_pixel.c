/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:09:06 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 18:17:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32	render_wall_pixel(Uint8 c[3], SDL_PixelFormat *format, t_wall wall)
{
	int	shadow;

	if (wall.dir == NORTH)
		shadow = 50;
	else if (wall.dir == WEST)
		shadow = 30;
	else if (wall.dir == EAST)
		shadow = 10;
	else
		shadow = 0;
	shadow += wall.dist * 4;
	c[0] -= (c[0] > shadow ? shadow : c[0]);
	c[1] -= (c[1] > shadow ? shadow : c[1]);
	c[2] -= (c[2] > shadow ? shadow : c[2]);
	return (SDL_MapRGB(format, c[0], c[1], c[2]));
}
