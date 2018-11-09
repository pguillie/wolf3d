/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:40:52 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 16:55:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int	ft_pnm_get_type(t_pnm data, t_pnm_type *type)
{
	if (type)
	{
		*type = data.type;
		return (0);
	}
	return (-1);
}

int	ft_pnm_set_type(t_pnm *data, t_pnm_type type)
{
	if (data == NULL)
		return (-1);
	if (type == pbm)
	{
		data->depth = 1;
		ft_pnm_set_maxval(data, 1);
	}
	else if (type == pgm)
	{
		data->depth = 1;
		ft_pnm_set_maxval(data, 255);
	}
	else if (type == ppm)
	{
		data->depth = 3;
		ft_pnm_set_maxval(data, 255);
	}
	else
		return (-1);
	data->type = type;
	return (0);
}
