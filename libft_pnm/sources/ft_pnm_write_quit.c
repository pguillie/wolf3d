/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_write_quit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:39:06 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 16:47:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int		ft_pnm_write_quit(t_pnm *data)
{
	int	ret;

	if (data == NULL)
		return (-1);
	ret = close(data->file);
	data->file = -1;
	data->width = 0;
	data->height = 0;
	data->plain = 0;
	return (ret);
}
