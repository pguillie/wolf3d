/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_texture.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:08:02 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/12 23:40:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TEXTURE_H
# define T_TEXTURE_H

# include <stdint.h>

# define NB_TEXTURE 4

# define T_BRICKS_FILE "textures/bricks_l.pnm"
# define T_METAL_FILE "textures/metal_l.pnm"
# define T_STONE_FILE "textures/stone_l.pnm"
# define T_WOOD_FILE "textures/wood_l.pnm"

enum	e_texture
{
	T_BRICKS,
	T_METAL,
	T_STONE,
	T_WOOD,
	T_DFLT,
};

#endif
