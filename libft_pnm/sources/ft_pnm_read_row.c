/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_read_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:19 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 14:58:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static int	ft_pnm_read_row_plain_sample(t_pnm data, uint16_t *sample, char c)
{
	uint16_t	tmp;

	*sample = 0;
	while (!ft_isspace(c))
	{
		if (!ft_isdigit(c))
			return (-1);
		tmp = *sample;
		*sample = tmp * 10 + c - '0';
		if (*sample < tmp)
			return (0);
		if (read(data.file, &c, 1) == 0)
			return (-1);
	}
	if (*sample > data.maxval)
		return (-1);
	return (0);
}

static int	ft_pnm_read_row_plain(t_pnm data, uint16_t **row)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.depth)
		{
			if (read(data.file, &c, 1) == 0)
				return (-1);
			while (ft_isspace(c))
				if (read(data.file, &c, 1) == 0)
					return (-1);
			if (ft_pnm_read_row_plain_sample(data, row[i] + j, c) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_pnm_read_row_raw_one(t_pnm data, uint16_t **row)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.depth)
		{
			row[i][j] = 0;
			if (read(data.file, row[i] + j, 1) == 0)
				return (-1);
			if (row[i][j] > data.maxval)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_pnm_read_row_raw_two(t_pnm data, uint16_t **row)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.depth)
		{
			if (read(data.file, (uint8_t *)(row[i] + j) + 1, 1) == 0)
				return (-1);
			if (read(data.file, (uint8_t *)(row[i] + j), 1) == 0)
				return (-1);
			if (row[i][j] > data.maxval)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_pnm_read_row(t_pnm data, uint16_t **row)
{
	if (data.file < 0 || row == NULL)
		return (-1);
	if (data.type == pbm)
		return (ft_pnm_read_pbm_row(data, row));
	if (data.plain)
		return (ft_pnm_read_row_plain(data, row));
	if (data.bytes_per_sample == 1)
		return (ft_pnm_read_row_raw_one(data, row));
	return (ft_pnm_read_row_raw_two(data, row));
}
