/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 01:05:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	render_surface(SDL_Renderer *renderer, SDL_Surface *surface)
{
	SDL_Texture	*texture;

	SDL_LockSurface(surface);
	ft_memcpy(surface->pixels, surface->userdata, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	texture = SDL_CreateTextureFromSurface(
		renderer, surface);
	if (texture == NULL)
		return (-1);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(texture);
	return (0);
}

int			render_image(t_engine data)
{
	int	x;

	x = 0;
	while (x < data.window.w)
	{
		render_column(data, x++);
	}
	return (render_surface(data.window.renderer, data.window.surface));
}
