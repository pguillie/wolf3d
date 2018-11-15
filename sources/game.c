/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:28:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/14 19:57:43 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	game_update_fov(struct s_window *win)
{
	win->fov = 2 * atan(0.5) * win->w / win->h;
	if (win->fov * 180 / M_PI > FOV_MAX)
	{
		win->fov = FOV_MAX * M_PI / 180;
		win->calc_h = 2 * atan(0.5) * win->w / win->fov;
	}
	else
		win->calc_h = win->h;
}

void		game(t_engine data)
{
	int		loop;
	// clock_t	cur;
	// clock_t	last;
	// clock_t	delay;

	loop = 1;
	// delay = 0;
	// last = clock();
	while (loop)
	{
		game_update_fov(&(data.window));
		// printf("fov: %f rad = %f C\n", data.window.fov, data.window.fov * 180 / M_PI);
		// cur = clock();
		// printf("fps: %.2f\n", (float)CLOCKS_PER_SEC / (cur - last));
		// printf("delay: %lu cur: %lu last: %lu\n", delay, cur, last);
		loop = game_event(&data);
		// if ((delay += cur - last) > UPDATE_DELAY)
		// {
			game_update(&data);
		// 	delay = 0;
		// }
		render_image(data);
		// last = cur;
	}
}
