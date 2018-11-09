/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_read_quit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:27:02 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 17:06:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int		ft_pnm_read_quit(t_pnm *data)
{
	int	ret;

	if (data == NULL)
		return (-1);
	ret = close(data->file);
	data->file = -1;
	data->width = 0;
	data->height = 0;
	data->plain = 0;
	data->type = 0;
	data->maxval = 0;
	data->depth = 0;
	data->bytes_per_sample = 0;
	return (ret);
}
