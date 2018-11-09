/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_plainformat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:32:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 16:47:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

int	ft_pnm_get_plainformat(t_pnm data, int *plainformat)
{
	if (plainformat)
		*plainformat = data.plain;
	return (data.plain);
}

int	ft_pnm_set_plainformat(t_pnm *data, int plainformat)
{
	if (data == NULL)
		return (-1);
	data->plain = !(!plainformat);
	return (data->plain);
}
