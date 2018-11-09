/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:28:35 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/03 11:00:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int nbr, int fd)
{
	char	c;

	if (nbr > 9)
		if (ft_putnbr_fd(nbr / 10, fd) < 0)
			return (-1);
	c = nbr % 10 + '0';
	return (write(fd, &c, 1));
}
