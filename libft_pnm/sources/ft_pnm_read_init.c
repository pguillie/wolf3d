/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_read_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:39:12 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 17:46:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static size_t		ft_pnm_read_comment(int fd, char *buf, size_t count)
{
	size_t	i;
	int		comment;

	i = 0;
	comment = 0;
	while (i < count)
	{
		if (read(fd, buf + i, 1) == 0)
			return (i);
		if (buf[i] == '#')
			comment = 1;
		else if (comment && (buf[i] == '\r' || buf[i] == '\n'))
			comment = 0;
		else if (!comment)
			i++;
	}
	return (i);
}

static int			ft_pnm_read_init_magic(int fd)
{
	char	magic_number[2];

	if (ft_pnm_read_comment(fd, magic_number, 2) < 2 || magic_number[0] != 'P')
		return (0);
	if (magic_number[1] < '1' || magic_number[1] > '6')
		return (0);
	return (magic_number[1] - '0');
}

static unsigned int	ft_pnm_read_init_dim(int fd)
{
	char			c;
	unsigned int	dim;
	unsigned int	t;

	if (ft_pnm_read_comment(fd, &c, 1) == 0)
		return (0);
	while (ft_isspace(c))
		if (ft_pnm_read_comment(fd, &c, 1) == 0)
			return (0);
	dim = 0;
	while (!ft_isspace(c))
	{
		if (!ft_isdigit(c))
			return (0);
		t = dim;
		dim = t * 10 + c - '0';
		if (dim < t)
			return (0);
		if (ft_pnm_read_comment(fd, &c, 1) == 0)
			return (0);
	}
	return (dim);
}

static uint16_t		ft_pnm_read_maxval(int fd)
{
	char		c;
	uint16_t	maxval;
	uint16_t	t;

	if (ft_pnm_read_comment(fd, &c, 1) == 0)
		return (0);
	while (ft_isspace(c))
		if (ft_pnm_read_comment(fd, &c, 1) == 0)
			return (0);
	maxval = 0;
	while (!ft_isspace(c))
	{
		if (!ft_isdigit(c))
			return (0);
		t = maxval;
		maxval = t * 10 + c - '0';
		if (maxval < t)
			return (0);
		if (ft_pnm_read_comment(fd, &c, 1) == 0)
			return (0);
	}
	return (maxval);
}

int					ft_pnm_read_init(char *file, t_pnm *data)
{
	int	fd;

	if (file == NULL || data == NULL)
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if ((data->type = ft_pnm_read_init_magic(fd)) == 0)
		return (-1);
	data->plain = (data->type > 3 ? 0 : 1);
	if (ft_pnm_set_type(data, data->type > 3 ? data->type - 3 : data->type) < 0)
		return (-1);
	if ((data->width = ft_pnm_read_init_dim(fd)) == 0)
		return (-1);
	if ((data->height = ft_pnm_read_init_dim(fd)) == 0)
		return (-1);
	if ((data->maxval = (data->type == pbm ? 1 : ft_pnm_read_maxval(fd))) == 0)
		return (-1);
	data->bytes_per_sample = (data->maxval < 256 ? 1 : 2);
	data->file = fd;
	return (0);
}
