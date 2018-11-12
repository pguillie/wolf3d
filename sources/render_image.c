/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 10:34:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_column(t_wall wall, struct s_window win, int col,
	uint8_t ***texture)
{
	SDL_Point	pts[win.h / 2];
	int			height;
	int			margin;
	int			i;
	int			row;

	height = win.h / wall.dist;
	margin = (win.h - height) / 2;
	if (margin < 0)
	{
		i = 0;
		while (i < win.h)
		{
			row = (i - margin) * TEXTURE_SIZE / height;
			SDL_SetRenderDrawColor(win.renderer,
				texture[row][wall.col][0],
				texture[row][wall.col][1],
				texture[row][wall.col][2],
				255);
			SDL_RenderDrawPoint(win.renderer, col, i++);
		}
	}
	else
	{
		i = 0;
		while (i < margin)
		{
			pts[i].y = i;
			pts[i++].x = col;
		}
		SDL_SetRenderDrawColor(win.renderer, 42, 42, 42, 255);
		SDL_RenderDrawPoints(win.renderer, pts, margin);
		while (i < height + margin)
		{
			row = (i - margin) * TEXTURE_SIZE / height;
			SDL_SetRenderDrawColor(win.renderer,
				texture[row][wall.col][0],
				texture[row][wall.col][1],
				texture[row][wall.col][2],
				255);
			SDL_RenderDrawPoint(win.renderer, col, i++);
		}
		while (i < win.h)
		{
			pts[i - margin - height].y = i;
			pts[i++ - margin - height].x = col;
		}
		SDL_SetRenderDrawColor(win.renderer, 142, 142, 142, 255);
		SDL_RenderDrawPoints(win.renderer, pts, win.h - height - margin);
	}
}

static void	render_column_col(t_wall wall, struct s_window win, int col)
{
	SDL_Point	pts[win.h];
	int			i;
	int			j;
	int			h;

	i = 0;
	while (i < win.h)
	{
		pts[i].x = col;
		pts[i].y = i;
		i++;
	}
	h = win.h / wall.dist;
	i = (wall.dist > 1 ? win.h / 2 - h / 2 : 0);
	j = (wall.dist > 1 ? win.h / 2 + h / 2 : win.h);
	SDL_SetRenderDrawColor(win.renderer, 42, 42, 42, 255);
	SDL_RenderDrawPoints(win.renderer, pts, i);
	SDL_SetRenderDrawColor(win.renderer, 200, 0, 0, 255);
	SDL_RenderDrawPoints(win.renderer, pts + i, j - i);
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
		if (w.texture == T_DFLT)
			w.texture = (enum e_texture)w.dir;
		if (data.textures[w.texture])
			render_column(w, data.window, px, data.textures[w.texture]);
		else
			render_column_col(w, data.window, px);
		// printf("rend: %.2f\n", (float)(clock() - a));
		px++;
		data.player.dir -= angle;
	}
	SDL_RenderPresent(data.window.renderer);
}
