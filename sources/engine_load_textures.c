/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_load_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:34:23 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 20:45:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_texture_file(char *file, enum e_texture t)
{
	if (t == T_BRICKS)
		ft_strcpy(file, T_BRICKS_FILE);
	else if (t == T_METAL)
		ft_strcpy(file, T_METAL_FILE);
	else if (t == T_STONE)
		ft_strcpy(file, T_STONE_FILE);
	else if (t == T_WOOD)
		ft_strcpy(file, T_WOOD_FILE);
}

static int	get_file_path(char *file, int quality)
{
	int	len;

	ft_strcpy(file, "textures/");
	len = 9;
	if (quality == 1)
	{
		ft_strcat(file, "low/");
		len += 4;
	}
	else if (quality == 2)
	{
		ft_strcat(file, "medium/");
		len += 7;
	}
	else if (quality == 3)
	{
		ft_strcat(file, "high/");
		len += 5;
	}
	return (len);
}

int			engine_load_textures(t_engine *data)
{
	char	file[128];
	int		i;
	int		ret;
	int		begin;

	begin = get_file_path(file, data->quality);
	ret = 0;
	i = 0;
	while (i < NB_TEXTURE)
	{
		get_texture_file(file + begin, i);
		data->textures[i] = load_texture(file);
		if (data->textures[i] == NULL)
			ret = ELOADTEXTURE;
		i++;
	}
	ft_strcpy(file + begin, T_SKY_FILE);
	if ((data->sky = load_texture(file)) == NULL)
		ret = ELOADTEXTURE;
	return (ret);
}
