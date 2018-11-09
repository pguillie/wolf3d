/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_write_row.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:17:07 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 19:01:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static int		ft_pnm_write_row_plain(t_pnm data, uint16_t **row)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.depth)
		{
			if (row[i][j] > data.maxval)
				return (-1);
			if (ft_putnbr_fd(row[i][j], data.file) < 0)
				return (-1);
			if (write(data.file, "\n", 1) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static uint8_t	*ft_pnm_write_one(uint16_t **row, int width, int depth)
{
	uint8_t	*buf;
	int		i;
	int		j;

	if ((buf = malloc(width * depth)))
	{
		i = 0;
		while (i < width)
		{
			j = 0;
			while (j < depth)
			{
				buf[i * depth + j] = row[i][j];
				j++;
			}
			i++;
		}
	}
	return (buf);
}

static uint8_t	*ft_pnm_write_two(uint16_t **row, int width, int depth)
{
	uint8_t	*buf;
	int		i;
	int		j;

	if ((buf = malloc(2 * width * depth)))
	{
		i = 0;
		while (i < width)
		{
			j = 0;
			while (j < depth)
			{
				ft_memcpy(buf + 2 * (depth * i + j),
					(void *)(row[i] + j) + 1, 1);
				ft_memcpy(buf + 2 * (depth * i + j) + 1, row[i] + j, 1);
				j++;
			}
			i++;
		}
	}
	return (buf);
}

static int		ft_pnm_write_row_raw(t_pnm data, uint16_t **row)
{
	uint8_t	*buf;
	int		i;
	int		len;

	i = 0;
	if (data.bytes_per_sample == 1)
	{
		if ((buf = ft_pnm_write_one(row, data.width, data.depth)) == NULL)
			return (-1);
		len = data.width * data.depth;
	}
	else
	{
		if ((buf = ft_pnm_write_two(row, data.width, data.depth)) == NULL)
			return (-1);
		len = 2 * data.width * data.depth;
	}
	if (write(data.file, buf, len) < 0)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	return (0);
}

int				ft_pnm_write_row(t_pnm data, uint16_t **row)
{
	if (data.file < 0 || row == NULL)
		return (-1);
	if (data.type == pbm)
		return (ft_pnm_write_pbm_row(data, row));
	if (data.plain)
		return (ft_pnm_write_row_plain(data, row));
	return (ft_pnm_write_row_raw(data, row));
}
