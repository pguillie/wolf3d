/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:28:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 19:55:28 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		game(t_engine *data)
{
	int		loop;
	clock_t	cur;
	clock_t	last;
	clock_t	delay;

	delay = 0;
	last = clock();
	while ((loop = game_event(data)) == 1)
	{
		cur = clock();
		if ((delay += cur - last) > UPDATE_DELAY)
		{
			game_update(data);
			delay = 0;
		}
		render_image(*data);
		last = cur;
	}
	if (loop < 0)
		ft_perror(ESDLSURFACE);
}
