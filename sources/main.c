/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:46:56 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/19 19:03:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	get_wall_x(t_player p, t_map m)
{
	int		x;
	int		dx;
	float	y;
	float	a;

	a = -p.dir;
	if (a > -M_PI_2 && a < M_PI_2)
	{
		x = (int)ceilf(p.x);
		dx = 1;
	}
	else
	{
		x = (int)floorf(p.x);
		dx = -1;
	}
	y = p.y + (x - p.x) * tan(a);
	while (!(x < 0) && x < m.x && !(y < 0) && y < m.y
		&& m.layout[(int)floorf(y)][(dx > 0 ? x : x - 1)] == '0')
	{
		x += dx;
		y += dx * tan(a);
	}
	return (sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
}

float	get_wall_y(t_player p, t_map m)
{
	int		y;
	int		dy;
	float	x;
	float	a;

	a = -p.dir;
	if (a > 0)
	{
		y = (int)ceilf(p.y);
		dy = 1;
	}
	else
	{
		y = (int)floorf(p.y);
		dy =  -1;
	}
	x = p.x + (y - p.y) / tan(a);
	while (y >= 0 && y < m.y && x >= 0 && x < m.x
		&& m.layout[(dy > 0 ? y : y - 1)][(int)floorf(x)] == '0')
	{
		y += dy;
		x += dy / tan(a);
	}
	return (sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
}

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
	foo.dir = -M_PI_2;
	foo.x = 2.5;
	foo.y = 2.5;
	foo.fov = 60;
	printf("x : %f\n", get_wall_x(foo, map));
	printf("y : %f\n", get_wall_y(foo, map));

    // SDL_Quit();
	return (0);
}
