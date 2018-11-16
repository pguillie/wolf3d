/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:07:57 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 01:11:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_sky(t_engine data, int margin, int column, float angle)
{
	int	i;
	int	dim[2];
	int	xy[2];
	int	index;

	dim[0] = ((int *)data.sky)[0];
	dim[1] = ((int *)data.sky)[1];
	xy[0] = angle * dim[0] / (2 * M_PI);
	while (i < margin)
	{
		xy[1] = i * dim[1] * 2 / data.window.h;
		index = 2 * sizeof(int) + 3 * (dim[0] * xy[1] + xy[0]);
		*(Uint32 *)(data.window.surface->userdata
			+ i * data.window.surface->pitch
			+ column * data.window.surface->format->BytesPerPixel) =
				SDL_MapRGB(data.window.surface->format,
					data.sky[index], data.sky[index + 1], data.sky[index + 2]);
		i++;
	}
}
