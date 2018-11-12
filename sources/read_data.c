/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:18 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 19:21:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_error	layout_append(t_engine *data, char *line)
{
	char	**new_layout;
	int		height;
	int		width;

	height = data->map.h + 1;
	width = ft_strlen(line);
	if (width > data->map.w)
		data->map.w = width;
	new_layout = (char **)malloc(height * sizeof(char *));
	if (new_layout == NULL)
		return (ENOMEM);
	data->map.h = height;
	new_layout[--height] = line;
	while (height--)
		new_layout[height] = data->map.layout[height];
	if (data->map.h > 1)
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

static t_error	player_init(t_engine *data)
{
	int	i[3];

	i[0] = 0;
	i[2] = 0;
	while (i[0] < data->map.h)
	{
		i[1] = 0;
		while (i[1] < data->map.w)
		{
			if ((!i[2] && data->map.layout[i[0]][i[1]] == ' ')
				|| data->map.layout[i[0]][i[1]] == 'x')
			{
				i[2] = 1;
				data->player.y = i[0] + 0.5;
				data->player.x = i[1] + 0.5;
				data->map.layout[i[0]][i[1]] = ' ';
			}
			i[1]++;
		}
		i[0]++;
	}
	data->player.dir = 0;
	memset(data->player.move, 0, 4 * sizeof(t_move));
	memset(data->player.rotate, 0, 2 * sizeof(t_rotate));
	return (i[2] ? ENONE : ESETPOS);
}

t_error			read_data(const char *file, t_engine *data)
{
	char	*line;
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (EFOPEN);
	data->map.w = 0;
	data->map.h = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		if ((ret = layout_append(data, line)))
			break ;
	close(fd);
	if (ret == 0)
		ret = layout_regularize(data);
	if (ret == 0)
		ret = player_init(data);
	if (ret)
	{
		delete_data(*data);
		return (ret < 0 ? EFREAD : ret);
	}
	return (ENONE);
}
