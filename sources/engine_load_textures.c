/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_load_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:34:23 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 19:32:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*get_texture_file(enum e_texture t)
{
	if (t == T_BRICKS)
		return (T_BRICKS_FILE);
	if (t == T_METAL)
		return (T_METAL_FILE);
	if (t == T_STONE)
		return (T_STONE_FILE);
	if (t == T_WOOD)
		return (T_WOOD_FILE);
	return (NULL);
}

int			engine_load_textures(t_engine *data)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < NB_TEXTURE)
	{
		data->textures[i] = load_texture(get_texture_file(i));
		if (data->textures[i] < 0)
			ret = ELOADTEXTURE;
		i++;
	}
	return (ret);
}
