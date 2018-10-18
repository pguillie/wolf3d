#ifndef WOLF_ENGINE_H
# define WOLF_ENGINE_H

struct s_map
{
	int x;
	int y;
	char **layout;
};

struct s_player
{
	float x;
	float y;
	float dir;
	int fov;
};

struct s_engine
{
	//map;
	struct s_player player;
};

typedef struct s_map t_map; //
typedef struct s_player t_player; //
typedef struct s_engine t_engine;

#endif
