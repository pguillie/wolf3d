/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_maxval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:22:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 12:23:54 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int	ft_pnm_get_maxval(t_pnm data, uint16_t *maxval)
{
	if (maxval)
		*maxval = data.maxval;
	if (!data.maxval)
		return (-1);
	return (0);
}

int	ft_pnm_set_maxval(t_pnm *data, uint16_t maxval)
{
	if (data == NULL || data->type == pbm)
		return (-1);
	if (maxval)
	{
		data->maxval = maxval;
		data->bytes_per_sample = (maxval < 256 ? 1 : 2);
	}
	return (0);
}
