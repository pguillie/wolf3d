/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:28:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 20:05:15 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		data.window.fov = (float)data.window.w / ((float)data.window.h) * 2 * atan(0.5);
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
