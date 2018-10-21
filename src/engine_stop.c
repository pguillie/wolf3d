/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:53:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/21 21:14:54 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_data(t_engine data)
{
	int	i;

	i = 0;
	while (i < data.map.h)
		free(data.map.layout[i++]);
	free(data.map.layout);
}

void	engine_stop(t_engine data)
{
	delete_data(data);
	SDL_DestroyWindow(data.window.ptr);
	SDL_Quit();
}
