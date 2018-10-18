#include "wolf3d.h"

//////
void ft_bar(t_player p, t_map m)
{

	// x
	int x;
	float y;
	if (p.dir < M_PI_2 || p.dir > M_PI + M_PI_2)
	{
		x = (int)ceilf(p.x);
		y = p.y + (x - p.x) / tan(p.dir);
	}
	else
	{
		x = (int)floorf(p.x);
		y = p.y + (p.x - x) / tan(p.dir);
	}
	// printf("%f + (%f - %d) / %f = %f\n", p.y, p.x, x, tan(p.dir), y);
	printf("%d, %d : %c\n", x, (int)y, m.layout[(int)floorf(y)][x]);
	while (y < m.y && x < m.x && m.layout[(int)floorf(y)][x] == '0')
	{
		x += 1;
		y = y + 1 / tan(p.dir);
		printf("%d, %d : %c\n", x, (int)y, m.layout[(int)floorf(y)][x]);
	}
	// printf("%d, %d : %c\n", x, (int)y, m.layout[(int)y][x]);



	// y
	if (p.dir < M_PI)
		y = p.y / UNIT * UNIT;
	else
		y = (p.y / UNIT + 1) * UNIT;
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
	foo.x = 0.3;
	foo.y = 2.3;
	foo.fov = 60;
	ft_bar(foo, map);
	
    // SDL_Quit();
	return (0);
}
