/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:50:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/23 10:48:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_colum(t_wall wall, struct s_window win, int col)
{
	int	i;
	int	wall_top;
	int	wall_bot;
	int	shadow_dir;

	i = 0;
	wall_top = win.h / 2 - (win.h / wall.dist) / 2;
	wall_bot = win.h / 2 + (win.h / wall.dist) / 2;
	while (i < win.h)
	{
		if (i < wall_top)
			SDL_SetRenderDrawColor(win.renderer, 42, 42, 42, 255);
		else if (i > wall_bot)
			SDL_SetRenderDrawColor(win.renderer, 84, 84, 84, 255);
		else
		{
			if (wall.dir == NORTH)
				shadow_dir = 100 + (int)(10 * wall.dist);
			else if (wall.dir == SOUTH)
				shadow_dir = 0 + (int)(10 * wall.dist);
			else if (wall.dir == EAST)
				shadow_dir = 20 + (int)(10 * wall.dist);
			else if (wall.dir == WEST)
				shadow_dir = 60 + (int)(10 * wall.dist);
			SDL_SetRenderDrawColor(win.renderer, 200 - shadow_dir, 0, 0, 255);
		}
		SDL_RenderDrawPoint(win.renderer, col, i);
		i++;
	}
}

void		render_image(t_engine data)
{
	t_wall	w;
	float	angle;
	float	fovr;
	int		px;

	px = 0;
	// printf("DIRECTION: %f\n", data.player.dir);
	angle = data.player.dir;
	fovr = data.player.fov * M_PI / 180;
	while (px < data.window.w)
	{
		data.player.dir = angle + fovr / 2
			- ((float)px * fovr) / data.window.w;
		/* float foo =  */get_wall(data, &w);
		w.dist *= cos(angle - data.player.dir);
		// printf(/* "dir: %f,  */"dist: %f\n", /* data.player.dir,  */foo);
		render_colum(w, data.window, px);
		px++;
	}
	SDL_RenderPresent(data.window.renderer);
}
