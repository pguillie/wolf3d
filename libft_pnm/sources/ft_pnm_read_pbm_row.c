/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_read_pbm_row.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:21:03 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 19:01:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static int	ft_pnm_read_pbm_row_plain(t_pnm data, u_int16_t **row)
{
	char	c;
	int		i;

	i = 0;
	while (i < data.width)
	{
		if (read(data.file, &c, 1) == 0)
			return (-1);
		while (ft_isspace(c))
			if (read(data.file, &c, 1) == 0)
				return (-1);
		if (c == '0' || c == '1')
			row[i++][0] = !(c - '0');
		else
			return (-1);
	}
	return (0);
}

static int	ft_pnm_read_pbm_row_raw(t_pnm data, uint16_t **row)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < data.width)
	{
		if (read(data.file, &c, 1) == 0)
			return (-1);
		j = 8;
		while (j-- && i < data.width)
			row[i++][0] = (c & (1 << j) ? 0 : 1);
	}
	return (0);
}

int			ft_pnm_read_pbm_row(t_pnm data, uint16_t **row)
{
	if (data.plain)
		return (ft_pnm_read_pbm_row_plain(data, row));
	return (ft_pnm_read_pbm_row_raw(data, row));
}
