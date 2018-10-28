/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:28:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/26 19:47:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		game(t_engine data)
{
	int		loop;
	clock_t	cur;
	clock_t	last;

	loop = 1;
	last = clock();
	while (loop)
	{
		cur = clock();
		printf("fps: %.2f\n", (float)CLOCKS_PER_SEC / (cur - last));
		game_update(&data);
		render_image(data);
		loop = game_event(&data);
		last = cur;
	}
}
