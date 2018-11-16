/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:50:07 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/16 18:09:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <SDL2/SDL.h>
# include <fcntl.h>

# include "libft.h"
# include "libft_pnm.h"
# include "types/t_coord.h"
# include "types/t_engine.h"
# include "types/t_error.h"
# include "types/t_move.h"
# include "types/t_rotate.h"
# include "types/t_wall.h"

// debug
#include <stdio.h>
#include <time.h>
//

t_error		engine_start(t_engine *engine_data, const char *data_file);
void		engine_stop(t_engine engine_data);
int			engine_load_textures(t_engine *data);

t_error		read_data(const char *file, t_engine *data);
uint8_t		*load_texture(char *file);

void		delete_data(t_engine data);
void		delete_textures(t_engine data);

void		game(t_engine data);
int			game_event(t_engine *data);
void		game_update(t_engine *data);
void		game_move(t_engine *data, float angle);
void		game_rotate(t_engine *data, int sign);

int			render_image(t_engine data);
void		render_column(t_engine data, int colum);
void		render_sky(t_engine data, int margin, int column, float angle);
void		render_wall(t_engine data, t_wall wall, int *limits, int column);
void		render_floor(t_engine data, int begin, int column);
float		get_wall(t_engine data, t_wall *w, float angle);

int			ft_perror(t_error no);

#endif
