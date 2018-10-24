/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:18 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/24 15:54:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// static t_error	player_init(t_engine *data, char **line)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*line[i])
// 	{
// 		if (*line[i] == 'x')
// 		{
// 			if (!(data->player.x < 0))
// 				return (EALRDSET)
// 		}
// }

// static t_error	layout_append(t_engine *data, char *line)
// {
// 	char	**new_layout;
// 	int		size;

// 	size = data->map.h;
// 	data->map.h += 1;
// 	new_layout = (char **)malloc(data->map.h * sizeof(char *));
// 	if (new_layout == NULL)
// 		return (ENOMEM);
// 	while (size--)
// 		new_layout[size] = data->map.layout[size];
// 	new_layout[data->map.h] = line;
// 	free(data->map.layout);
// 	data->map.layout = new_layout;
// 	return (ENONE);
// }

t_error			read_data(const char *file, t_engine *data)
// {
// 	char	*line;
// 	int		fd;
// 	int		ret;

// 	if ((fd = open(file, O_RDONLY)) < 0)
// 		return (EFOPEN);
// 	while ((ret = get_next_line(fd, &line)))
// 	{
// 		player_init(data, &line);
// 		layout_append(data, line);
// 	}
// 	return (ENONE);
// }

{
	(void)file;
	data->map.layout = (char**)malloc(6 * sizeof(char *));
	data->map.layout[0] = strdup("ww w w www");
	data->map.layout[1] = strdup("          ");
	data->map.layout[2] = strdup("ww   o   w");
	data->map.layout[3] = strdup("          ");
	data->map.layout[4] = strdup("w       ww");
	data->map.layout[5] = strdup("w w w w  w");
	data->map.w = 10;
	data->map.h = 6;
	data->player.x = 5.5;
	data->player.y = 3.5;
	data->player.dir = 0;
	data->player.fov = 60;
	data->player.speed = 10;
	memset(data->player.move, 0, 4 * sizeof(t_move));
	memset(data->player.rotate, 0, 2 * sizeof(t_rotate));
	return (0);
}
