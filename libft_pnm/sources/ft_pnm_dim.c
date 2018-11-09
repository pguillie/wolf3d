/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_dim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:58:35 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 16:47:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int	ft_pnm_get_dim(t_pnm data, int *width, int *height)
{
	if (width)
		*width = data.width;
	if (height)
		*height = data.height;
	if (!data.width || !data.height)
		return (-1);
	return (0);
}

int	ft_pnm_set_dim(t_pnm *data, int width, int height)
{
	if (data == NULL)
		return (-1);
	if (width)
		data->width = width;
	if (height)
		data->height = height;
	return (0);
}
