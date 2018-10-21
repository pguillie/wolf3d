/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:55:38 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/21 21:05:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_perror(t_error no)
{
	const char	*err[] = {
		"unknown error",
		"Usage: wolf3d data_file",
		"Unable to initialize SDL",
		"Unable to create window"
	};

	write(2, err[no], ft_strlen(err[no]));
	write(2, "\n", 1);
	return (no);
}
