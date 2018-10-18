#include "wolf3d.h"

//////
float ft_barx(t_player p, t_map m)
{
	int x;
	float y;

	if (p.dir < M_PI_2 || p.dir > M_PI + M_PI_2)
	{
		x = (int)ceilf(p.x);
		y = p.y - (x - p.x) / tan(p.dir);
		while (x < m.x && y >= 0 && y < m.y && m.layout[(int)floorf(y)][x] == '0')
		{
			x += 1;
			y = y - 1 / tan(p.dir);
		}
	}
	else
	{
		x = (int)floorf(p.x);
		y = p.y - (p.x - x) / tan(p.dir);
		while (x >= 0 && y >= 0 && y < m.y && m.layout[(int)floorf(y)][x] == '0')
		{
			x -= 1;
			y = y + 1 / tan(p.dir);
		}
	}
	return (sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
}

float ft_bary(t_player p, t_map m)
{
	int y;
	float x;

	if (p.dir < M_PI)
	{
		y = (int)floorf(p.y);
		x = p.x + (p.y - y) * tan(p.dir);
		while (y >= 0 && x >= 0 && x < m.x && m.layout[y][(int)floorf(x)] == '0')
		{
			y -= 1;
			x = x - 1 * tan(p.dir);
		}
	}
	else
	{
		y = (int)ceilf(p.y);
		x = p.x + (y - p.y) * tan(p.dir);
		while (y < m.y && x >= 0 && x < m.x && m.layout[y][(int)floorf(x)] == '0')
		{
			y += 1;
			x = x + 1 * tan(p.dir);
		}
	}
	return (sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
}
//////

// int	main(int ac, char *av[])
int	main(void)
{
	// read map file
	t_map map;
	map.x = map.y = 5;
	map.layout = (char **)malloc(6 * sizeof(char *));
	map.layout[0] = strdup("11111");
	map.layout[1] = strdup("10001");
	map.layout[2] = strdup("10001");
	map.layout[3] = strdup("10001");
	map.layout[4] = strdup("11111");
	
	// SDL_Init(SDL_INIT_VIDEO);

	///
	t_player foo;
	foo.dir = M_PI_4;
	foo.x = 3;
	foo.y = 3;
	foo.fov = 60;
	printf("x : %f\n", ft_barx(foo, map));
	printf("y : %f\n", ft_bary(foo, map));
	
    // SDL_Quit();
	return (0);
}
