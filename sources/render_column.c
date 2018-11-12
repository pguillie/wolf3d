/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:55:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 23:43:44 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// opti + mise au propre + norme

void	render_column(t_wall wall, struct s_window win, int col, uint8_t *t)
{
	SDL_Point	pts[win.h / 2];
	int			height;
	int			margin;
	int			i;
	int			irow;
	int			icol;

	height = win.h / wall.dist;
	margin = (win.h - height) / 2;
	icol = wall.col * ((int *)t)[0];
	if (margin < 0)
	{
		i = 0;
		while (i < win.h)
		{
			irow = (i - margin) * ((int *)t)[1] / height;
			SDL_SetRenderDrawColor(win.renderer,
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 0],
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 1],
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 2],
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
		SDL_SetRenderDrawColor(win.renderer, 71, 163, 226, 255);
		SDL_RenderDrawPoints(win.renderer, pts, margin);
		while (i < height + margin)
		{
			irow = (i - margin) * ((int *)t)[1] / height;
			SDL_SetRenderDrawColor(win.renderer,
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 0],
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 1],
				t[2 * sizeof(int) + 3 * (((int *)t)[0] * irow + icol) + 2],
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
