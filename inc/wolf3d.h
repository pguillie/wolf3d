/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:50:07 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/21 21:12:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <stdlib.h>
# include <math.h>
# include <SDL2/SDL.h>

# include "libft/libft.h"
# include "types/t_coord.h"
# include "types/t_engine.h"
# include "types/t_error.h"
# include "types/t_wall.h"

// debug
// # include <stdlib.h>
#include <string.h>
#include <stdio.h>
//

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

t_error	engine_start(t_engine *engine_data, const char *data_file);
void	engine_stop(t_engine engine_data);
void	game(t_engine data);

float	get_wall(t_engine data, t_wall *w);

int		ft_perror(t_error no);

#endif
