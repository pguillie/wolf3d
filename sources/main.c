/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.SDL_WINDOWPOS_UNDEFINED.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:46:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/20 17:03:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(void)
{
	// read map file
	t_map map;
	map.x = map.y = 5;
	map.layout = (char **)malloc(5 * sizeof(char *));
	map.layout[0] = strdup("11111");
	map.layout[1] = strdup("10001");
	map.layout[2] = strdup("10011");
	map.layout[3] = strdup("11111");
	map.layout[4] = strdup("11111");
	// 
	t_player foo;
	foo.dir = -(3 * M_PI_4);
	foo.x = 2.5;
	foo.y = 2.5;
	foo.fov = 60;
	// 

	t_engine a;
	a.map = map;
	a.player = foo;
	game_loop(a);

	return (0);
}
