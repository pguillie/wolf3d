/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_pnm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:18:36 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 23:58:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PNM_H
# define LIBFT_PNM_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

# include "types/t_pnm.h"
# include "libft.h"

int			ft_pnm_read_init(char *file, t_pnm *data);
int			ft_pnm_read_row(t_pnm data, uint16_t **row);
int			ft_pnm_read_pbm_row(t_pnm data, uint16_t **row);
int			ft_pnm_read_quit(t_pnm *data);

int			ft_pnm_write_init(char *file, t_pnm *data);
int			ft_pnm_write_row(t_pnm data, uint16_t **row);
int			ft_pnm_write_pbm_row(t_pnm data, uint16_t **row);
int			ft_pnm_write_quit(t_pnm *data);

uint16_t	**ft_pnm_alloc_row(t_pnm data);
void		ft_pnm_free_row(uint16_t **row, t_pnm data);

int			ft_pnm_get_type(t_pnm data, t_pnm_type *type);
int			ft_pnm_set_type(t_pnm *data, t_pnm_type type);

int			ft_pnm_get_dim(t_pnm data, int *width, int *height);
int			ft_pnm_set_dim(t_pnm *data, int width, int height);

int			ft_pnm_get_maxval(t_pnm data, uint16_t *maxval);
int			ft_pnm_set_maxval(t_pnm *data, uint16_t maxval);

int			ft_pnm_get_plainformat(t_pnm data, int *plainformat);
int			ft_pnm_set_plainformat(t_pnm *data, int plainformat);

#endif
