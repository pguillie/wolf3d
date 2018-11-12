/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 22:31:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	i = (wall.dist > 1 ? win.h / 2 - (win.h / wall.dist) / 2 : 0);
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
		get_wall(data, &w);
		w.dist *= cos(dir - data.player.dir);
		if (w.texture == T_DFLT)
			w.texture = (enum e_texture)w.dir;
		if (data.textures[w.texture])
			render_column(w, data.window, px, data.textures[w.texture]);
		else
			render_column_color(w, data.window, px);
		px++;
		data.player.dir -= angle;
	}
	SDL_RenderPresent(data.window.renderer);
}
