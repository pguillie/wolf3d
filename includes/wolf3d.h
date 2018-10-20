/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:47:05 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/20 18:14:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <stdlib.h>
# include <math.h>
# include <SDL2/SDL.h>
# include "wolf_engine.h"
//
#include <string.h>
#include <stdio.h>

int		game_loop(t_engine data);
float	get_wall(t_player p, t_map m, t_wall *w);

#endif
