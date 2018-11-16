/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 00:14:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

//
static void	render_sky(t_wall wall, struct s_window win, int col, uint8_t *sky, float dir)
{
	int	i;
	int	irow;
	int	icol;
	int	h;

	h = (win.real_h / wall.dist < win.h ?
		(win.h - (win.real_h / wall.dist)) / 2 : 0);
	dir = fmodf(dir + 2 * M_PI, 2 * M_PI);
	icol = dir * ((int *)sky)[0] / (2 * M_PI);
	i = win.real_h - win.h;
	while (i < h)
	{
		irow = i * ((int *)sky)[1] * 2 / win.real_h;
		SDL_SetRenderDrawColor(win.renderer,
			sky[2 * sizeof(int) + 3 * (((int *)sky)[0] * irow + icol) + 0],
			sky[2 * sizeof(int) + 3 * (((int *)sky)[0] * irow + icol) + 1],
			sky[2 * sizeof(int) + 3 * (((int *)sky)[0] * irow + icol) + 2],
			255);
		SDL_RenderDrawPoint(win.renderer, col, i);
		i++;
	}
}

static void	render_column_color(t_wall wall, struct s_window win, int col)
{
	SDL_Point	pts[win.h];
	int			i;

	i = 0;
	while (i < win.h)
	{
		pts[i].x = col;
		pts[i].y = i;
		i++;
	}
	i = (win.real_h / wall.dist < win.h ?
		(win.h - (win.real_h / wall.dist)) / 2 : 0);
	SDL_SetRenderDrawColor(win.renderer, 71, 163, 226, 255);
	SDL_RenderDrawPoints(win.renderer, pts, i);
	SDL_SetRenderDrawColor(win.renderer, 200, 0, 0, 255);
	SDL_RenderDrawPoints(win.renderer, pts + i, win.h - 2 * i);
	SDL_SetRenderDrawColor(win.renderer, 142, 142, 142, 255);
	SDL_RenderDrawPoints(win.renderer, pts + win.h - i, i);
}

void		render_image(t_engine data)
{
	t_wall	w;
	float	dir;
	float	angle;
	int		px;

	px = 0;
	dir = data.player.dir;
	data.player.dir += data.window.fov / 2;
	angle = data.window.fov / data.window.w;
	while (px < data.window.w)
	{
		get_wall(data, &w, data.player.dir);
		w.dist *= cos(dir - data.player.dir);
		if (w.texture == T_DFLT)
			w.texture = (enum e_texture)w.dir;
		// skybox
		render_sky(w, data.window, px, data.sky, data.player.dir);
		//
		if (data.textures[w.texture])
			render_column(w, data.window, px, data.textures[w.texture]);
		else
			render_column_color(w, data.window, px);
		px++;
		data.player.dir -= angle;
	}
	SDL_RenderPresent(data.window.renderer);
}
