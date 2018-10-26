/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:18 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/26 12:27:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_error	player_init_pos(t_engine *data, char **line)
{
	size_t	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == 'x')
		{
			if (!(data->player.x < 0))
				return (ESETPOS);
			data->player.x = (float)i + 0.5;
			data->player.y = (float)(data->map.h) - 0.5;
			(*line)[i] = ' ';
		}
		i++;
	}
	return (ENONE);
}

static t_error	layout_append(t_engine *data, char *line)
{
	char	**new_layout;
	int		height;
	int		width;

	height = ++data->map.h;
	width = ft_strlen(line);
	if (width > data->map.w)
		data->map.w = width;
	new_layout = (char **)malloc(data->map.h * sizeof(char *));
	if (new_layout == NULL)
		return (ENOMEM);
	new_layout[--height] = line;
	while (height--)
		new_layout[height] = data->map.layout[height];
	if (height > 1)
		free(data->map.layout);
	data->map.layout = new_layout;
	return (ENONE);
}

static t_error	layout_regularize(t_engine *data)
{
	char	*aligned;
	int		h;
	int		i;

	h = 0;
	while (h < data->map.h)
	{
		i = ft_strlen(data->map.layout[h]);
		if (i < data->map.w)
		{
			if ((aligned = (char *)malloc(data->map.w)) == NULL)
				return (ENOMEM);
			ft_memset(aligned + i, ' ', data->map.w - i);
			while (i--)
				aligned[i] = data->map.layout[h][i];
			free(data->map.layout[h]);
			data->map.layout[h] = aligned;
		}
		h++;
	}
	return (ENONE);
}

static void		player_init(t_engine *data)
{
	data->player.dir = 0;
	data->player.fov = (float)WIN_WIDTH / ((float)WIN_HEIGHT) * 2 * atan(0.5); // move to game loop, when resize
	memset(data->player.move, 0, 4 * sizeof(t_move));
	memset(data->player.rotate, 0, 2 * sizeof(t_rotate));
}

t_error			read_data(const char *file, t_engine *data)
{
	char	*line;
	int		fd;
	int		ret;

	data->player.x = -1;
	data->map.w = 0;
	data->map.h = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (EFOPEN);
	while ((ret = get_next_line(fd, &line)))
	{
		layout_append(data, line);
		if (player_init_pos(data, &line) == ESETPOS)
			return (ESETPOS);
	}
	if (ret < 0)
		return (EFREAD);
	if (data->player.x < 0)
		return (ESETPOS);
	layout_regularize(data);
	player_init(data);
	return (ENONE);
}
