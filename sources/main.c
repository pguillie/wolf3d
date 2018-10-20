/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:46:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/20 12:35:01 by paul             ###   ########.fr       */
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

	// SDL_Init(SDL_INIT_VIDEO);

	///
	t_player foo;
	foo.dir = -(3 * M_PI_4);
	foo.x = 2.5;
	foo.y = 2.5;
	foo.fov = 60;

	t_wall w;
	printf("%f\n", get_wall(foo, map, &w));
    // SDL_Quit();
	return (0);
}
