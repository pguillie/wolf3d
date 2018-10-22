/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:53:08 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/22 11:46:30 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	engine_stop(t_engine data)
{
	SDL_DestroyRenderer(data.window.renderer);
	SDL_DestroyWindow(data.window.ptr);
	SDL_Quit();
	delete_data(data);
}
