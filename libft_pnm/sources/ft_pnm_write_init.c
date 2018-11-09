/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_write_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:38:33 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 11:24:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

static int	ft_pnm_write_init_magic(int fd, t_pnm_type type, int plain)
{
	if (type == pbm)
		return (write(fd, (plain ? "P1\n" : "P4\n"), 3));
	if (type == pgm)
		return (write(fd, (plain ? "P2\n" : "P5\n"), 3));
	if (type == ppm)
		return (write(fd, (plain ? "P3\n" : "P6\n"), 3));
	return (-1);
}

static int	ft_pnm_write_init_comment(int fd, char *file)
{
	if (write(fd, "# ", 2) < 0)
		return (-1);
	if (write(fd, file, ft_strlen(file)) < 0)
		return (-1);
	if (write(fd, " - created with the libft_pnm\n", 30) < 0)
		return (-1);
	return (0);
}

static int	ft_pnm_write_init_dim(int fd, int width, int height)
{
	if (ft_putnbr_fd(width, fd) < 0)
		return (-1);
	if (write(fd, " ", 1) < 0)
		return (-1);
	if (ft_putnbr_fd(height, fd) < 0)
		return (-1);
	if (write(fd, "\n", 1) < 0)
		return (-1);
	return (0);
}

static int	ft_pnm_write_maxval(int fd, uint16_t maxval)
{
	if (ft_putnbr_fd(maxval, fd) < 0)
		return (-1);
	if (write(fd, "\n", 1) < 0)
		return (-1);
	return (0);
}

int			ft_pnm_write_init(char *file, t_pnm *data)
{
	int	fd;

	if (file == NULL || data == NULL || data->width == 0 || data->height == 0)
		return (-1);
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return (-1);
	if (ft_pnm_write_init_magic(fd, data->type, data->plain) < 0)
		return (-1);
	if (ft_pnm_write_init_comment(fd, file) < 0)
		return (-1);
	if (ft_pnm_write_init_dim(fd, data->width, data->height) < 0)
		return (-1);
	if (data->type != pbm)
		if (ft_pnm_write_maxval(fd, data->maxval) < 0)
			return (-1);
	data->file = fd;
	return (0);
}
