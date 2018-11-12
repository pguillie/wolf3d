/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:44:04 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 22:28:12 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static uint8_t	*load_texture_exit(t_pnm info, uint16_t **row, uint8_t *text)
{
	ft_pnm_free_row(row, info);
	ft_pnm_read_quit(&info);
	free(text);
	return (NULL);
}

static void		copy_row(uint8_t *t_row, uint16_t **f_row, t_pnm info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.width)
	{
		j = 0;
		while (j < 3)
		{
			if (j < info.depth)
				t_row[i * 3 + j] = f_row[i][j] * 255 / info.maxval;
			else
				t_row[i * 3 + j] = f_row[i][0] * 255 / info.maxval;
			j++;
		}
		i++;
	}
}

uint8_t			*load_texture(char *file)
{
	uint8_t		*texture;
	t_pnm		info;
	uint16_t	**row;
	int			i;

	if (ft_pnm_read_init(file, &info) < 0)
		return (NULL);
	texture = (uint8_t *)malloc(info.width * info.height * 3 + 2 * sizeof(int));
	if (texture == NULL)
		return (NULL);
	*((int *)texture) = info.width;
	*((int *)texture + 1) = info.height;
	if ((row = ft_pnm_alloc_row(info)) == NULL)
		return (NULL);
	i = 0;
	while (i < info.height)
	{
		if (ft_pnm_read_row(info, row) < 0)
			return (load_texture_exit(info, row, texture));
		copy_row(texture + 2 * sizeof(int) + 3 * i * info.width, row, info);
		i++;
	}
	ft_pnm_free_row(row, info);
	ft_pnm_read_quit(&info);
	return (texture);
}
