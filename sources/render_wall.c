/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:55:12 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 18:14:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_wall_color(struct s_window win, int wall_size[2], int column,
	t_wall wall)
{
	Uint8	c[3];
	int		i;
	int		j;

	if (wall_size[1] < win.h)
	{
		i = wall_size[0];
		j = wall_size[0] + wall_size[1];
	}
	else
	{
		i = 0;
		j = win.h;
	}
	while (i < j)
	{
		ft_memset(c, 255, 3);
		*(Uint32 *)(win.surface->userdata
			+ i * win.surface->pitch
			+ column * win.surface->format->BytesPerPixel) =
				render_wall_pixel(c, win.surface->format, wall);
		i++;
	}
}

static void	render_wall_texture(SDL_Surface *surface, int couple[3][2],
	uint8_t *texture, t_wall wall)
{
	Uint8	c[3];
	int		index;

	index = 2 * sizeof(int) + 3 * (couple[0][0] * couple[1][1] + couple[1][0]);
	ft_memcpy(c, texture + index, 3);
	*(Uint32 *)(surface->userdata
		+ couple[2][0] * surface->pitch
		+ couple[2][1] * surface->format->BytesPerPixel) =
			render_wall_pixel(c, surface->format, wall);
}

static void	render_wall_small(t_engine data, t_wall wall, int couple[3][2],
	int *limits)
{
	couple[2][0] = limits[0];
	while (couple[2][0] < limits[0] + limits[1])
	{
		couple[1][1] = (couple[2][0] - limits[0])
			* couple[0][1] / limits[1];
		render_wall_texture(
				data.window.surface, couple, data.textures[wall.texture], wall);
		couple[2][0]++;
	}
}

static void	render_wall_large(t_engine data, t_wall wall, int couple[3][2],
	int *limits)
{
	couple[2][0] = 0;
	while (couple[2][0] < data.window.h)
	{
		couple[1][1] = (couple[2][0] - limits[0] - 1)
			* couple[0][1] / limits[1];
		render_wall_texture(
				data.window.surface, couple, data.textures[wall.texture], wall);
		couple[2][0]++;
	}
}

void		render_wall(t_engine data, t_wall wall, int *limits, int column)
{
	int	couple[3][2];

	if (wall.texture == T_DFLT)
		wall.texture = (enum e_texture)wall.dir;
	if (data.textures[wall.texture])
	{
		couple[0][0] = ((int *)data.textures[wall.texture])[0];
		couple[0][1] = ((int *)data.textures[wall.texture])[1];
		couple[1][0] = wall.col * couple[0][0];
		couple[2][1] = column;
		if (limits[0] > 0)
			render_wall_small(data, wall, couple, limits);
		else
			render_wall_large(data, wall, couple, limits);
	}
	else
		render_wall_color(data.window, limits, column, wall);
}
