/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pnm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:55:24 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 17:33:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PNM_H
# define T_PNM_H

typedef enum	e_pnm_type
{
	pbm = 1,
	pgm,
	ppm
}				t_pnm_type;

struct	s_pnm
{
	int			file;
	int			width;
	int			height;
	int			plain;
	t_pnm_type	type;
	int			depth;
	uint16_t	maxval;
	int			bytes_per_sample;
};

typedef struct s_pnm	t_pnm;

#endif
