/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:07:57 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 22:29:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_sky_texture(t_engine data, int margin, int col, float angle)
{
	int	i;
	int	dim[2];
	int	xy[2];
	int	index;

	dim[0] = ((int *)data.sky)[0];
	dim[1] = ((int *)data.sky)[1];
	xy[0] = angle * dim[0] / (2 * M_PI);
	i = 0;
	while (i < margin)
	{
		xy[1] = i * dim[1] * 2 / data.window.h;
		index = 2 * sizeof(int) + 3 * (dim[0] * xy[1] + xy[0]);
		*(Uint32 *)(data.window.surface->userdata
			+ i * data.window.surface->pitch
			+ col * data.window.surface->format->BytesPerPixel) =
				SDL_MapRGB(data.window.surface->format,
					data.sky[index],
					data.sky[index + 1],
					data.sky[index + 2]);
		i++;
	}
}

static void	render_sky_color(SDL_Surface *surface, int col, int margin)
{
	int	i;

	i = 0;
	while (i < margin)
	{
		*(Uint32 *)(surface->userdata
		+ i * surface->pitch
		+ col * surface->format->BytesPerPixel) =
			SDL_MapRGB(surface->format, 0, 191, 255);
		i++;
	}
}

void		render_sky(t_engine data, int margin, int column, float angle)
{
	if (data.sky)
		render_sky_texture(data, margin, column, angle);
	else
		render_sky_color(data.window.surface, column, margin);
}
