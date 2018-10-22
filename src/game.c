/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:28:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 18:06:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		game(t_engine data)
{
	int			loop;

	loop = 1;
	while (loop)
	{
		render_image(data);
		loop = game_event(&data);
	}
}
