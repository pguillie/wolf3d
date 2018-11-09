/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_write_pbm_row.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:41:26 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 11:46:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static int	ft_pnm_write_pbm_row_plain(t_pnm data, uint16_t **row)
{
	char	byte[2];
	int		i;

	i = 0;
	while (i < data.width)
	{
		byte[0] = !row[i++][0] + '0';
		byte[1] = '\n';
		if (write(data.file, byte, 2) < 0)
			return (-1);
	}
	return (0);
}

static int	ft_pnm_write_pbm_row_raw(t_pnm data, uint16_t **row)
{
	char	byte;
	int		bit;
	int		i;

	i = 0;
	while (i < data.width)
	{
		byte = 0;
		bit = 8;
		while (bit--)
		{
			byte |= (i < data.width ? !row[i++][0] : 0) << bit;
		}
		if (write(data.file, &byte, 1) < 0)
			return (-1);
	}
	return (0);
}

int			ft_pnm_write_pbm_row(t_pnm data, uint16_t **row)
{
	if (data.plain)
		return (ft_pnm_write_pbm_row_plain(data, row));
	return (ft_pnm_write_pbm_row_raw(data, row));
}
