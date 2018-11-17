/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 22:58:56 by pguillie         ###   ########.fr       */
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

static void	*render_thread(void *thread)
{
	t_thread	*t;

	t = (t_thread *)thread;
	while (t->begin < t->end)
		render_column(t->data, t->begin++);
	return (NULL);
}

int			render_image(t_engine data)
{
	t_thread	thread[THREAD_NB];
	int			i;

	i = 0;
	while (i < THREAD_NB)
	{
		thread[i].data = data;
		thread[i].begin = i * data.window.w / THREAD_NB;
		thread[i].end = (i + 1) * data.window.w / THREAD_NB;
		if (pthread_create(&thread[i].id, NULL, render_thread, &thread[i]))
			break ;
		i++;
	}
	i = 0;
	while (i < THREAD_NB)
		pthread_join(thread[i++].id, NULL);
	return (render_surface(data.window.renderer, data.window.surface));
}
