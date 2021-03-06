/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:26:46 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/14 19:47:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_textures(t_engine data)
{
	int	i;

	i = NB_TEXTURE;
	while (i--)
		free(data.textures[i]);
	free(data.sky);
}
