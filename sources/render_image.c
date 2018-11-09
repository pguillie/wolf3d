/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 23:58:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_column(t_wall wall, struct s_window win, int col,
	uint8_t ***texture)
{
	SDL_Point	pts[win.h];
	int			i;
	int			j;

	i = 0;
	while (i < win.h)
	{
		pts[i].x = col;
		pts[i].y = i;
		i++;
	}
	i = (wall.dist > 1 ? win.h / 2 - (win.h / wall.dist) / 2 : 0);
	j = (wall.dist > 1 ? win.h / 2 + (win.h / wall.dist) / 2 : win.h);
	SDL_SetRenderDrawColor(win.renderer, 42, 42, 42, 255);
	SDL_RenderDrawPoints(win.renderer, pts, i);
	//
	(void)texture;
	SDL_SetRenderDrawColor(win.renderer, 200, 0, 0, 255);
	SDL_RenderDrawPoints(win.renderer, pts + i, j - i);
	//
	SDL_SetRenderDrawColor(win.renderer, 142, 142, 142, 255);
	SDL_RenderDrawPoints(win.renderer, pts + j, win.h - j);
}

void		render_image(t_engine data)
{
	t_wall	w;
	float	dir;
	float	angle;
	int		px;

//
// clock_t a;

	px = 0;
	// printf("DIRECTION: %f\n", data.player.dir);
	dir = data.player.dir;
	data.player.dir += data.window.fov / 2;
	angle = data.window.fov / data.window.w;
	while (px < data.window.w)
	{
		// a = clock();
		/* float foo =  */get_wall(data, &w);
		w.dist *= cos(dir - data.player.dir);
		// printf("calc: %.2f - ", (float)(clock() - a));
		// printf(/* "dir: %f,  */"dist: %f\n", /* data.player.dir,  */foo);
		// a = clock();
		render_column(w, data.window, px, data.textures[w.texture]);
		// printf("rend: %.2f\n", (float)(clock() - a));
		px++;
		data.player.dir -= angle;
	}
	SDL_RenderPresent(data.window.renderer);
}
