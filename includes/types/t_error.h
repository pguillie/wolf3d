/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:25:45 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/15 18:40:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ERROR_H
# define T_ERROR_H

enum	e_error
{
	ENONE,
	EUSAGE,
	EFOPEN,
	EFREAD,
	ESETPOS,
	ENOMEM,
	ESDLINIT,
	ESDLWINDOW,
	ESDLRENDERER,
	ESDLSURFACE,
	ELOADTEXTURE
};

typedef enum e_error	t_error;

#endif
