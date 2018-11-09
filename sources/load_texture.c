/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:44:04 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 23:49:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static uint8_t	***load_texture_exit(t_pnm info, uint16_t **row)
{
	ft_pnm_free_row(row, info);
	ft_pnm_read_quit(&info);
	return (NULL);
}

uint8_t			***alloc_texture_exit(uint8_t ***t, int i, int j)
{
	while (j--)
		free(t[i][j]);
	free(t[i--]);
	while (i--)
	{
		j = 3;
		while (j--)
			free(t[i][j]);
		free(t[i]);
	}
	return (NULL);
}

uint8_t			***alloc_texture(void)
{
	uint8_t	***t;
	int		i;
	int		j;

	if ((t = (uint8_t ***)malloc(sizeof(uint8_t **) * TEXTURE_SIZE)) == NULL)
		return (NULL);
	i = 0;
	while (i < TEXTURE_SIZE)
	{
		if ((t[i] = (uint8_t **)malloc(sizeof(uint8_t *) * TEXTURE_SIZE)) == NULL)
			return (alloc_texture_exit(t, i, j));
		j = 0;
		while (j < TEXTURE_SIZE)
		{
			if ((t[i][j] = (uint8_t *)malloc(sizeof(uint8_t) * 3)) == NULL)
				return (alloc_texture_exit(t, i, j));
			j++;
		}
		i++;
	}
	return (t);
}

static void		copy_row(uint8_t **t_row, uint16_t **f_row, t_pnm info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.width) //handle resize to TEXTURE_SIZE
	{
		j = 0;
		while (j < 3)
		{
			if (j < info.depth)
				t_row[i][j] = f_row[i][j] * 255 / info.maxval;
			else
				t_row[i][j] = f_row[i][0] * 255 / info.maxval;
			j++;
		}
		i++;
	}
}

uint8_t			***load_texture(char *file)
{
	uint8_t		***texture;
	t_pnm		info;
	uint16_t	**row;
	int			i;
	int			j;

	if (ft_pnm_read_init(file, &info) < 0)
		return (NULL);
	if ((texture = alloc_texture()) == NULL)
		return (NULL);
	if ((row = ft_pnm_alloc_row(info)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < info.height)
	{
		if (ft_pnm_read_row(info, row) < 0)
			return (load_texture_exit(info, row));
		// if (j == i * 16 / info.height) //handle resize to TEXTURE_SIZE
			copy_row(texture[j++], row, info);
		i++;
	}
	ft_pnm_free_row(row, info);
	ft_pnm_read_quit(&info);
	return (texture);
}
