/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:26:46 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 10:38:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_textures(t_engine data)
{
	int	i;
	int	j;
	int	k;

	i = NB_TEXTURE;
	while (i--)
	{
		j = 0;
		if (data.textures[i] == NULL)
			continue ;
		while (j < TEXTURE_SIZE)
		{
			k = 0;
			while (k < TEXTURE_SIZE)
			{
				free(data.textures[i][j][k++]);
			}
			free(data.textures[i][j++]);
		}
		free(data.textures[i]);
	}
}
