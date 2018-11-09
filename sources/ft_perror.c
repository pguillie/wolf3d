/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:55:38 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/24 19:28:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_perror(t_error no)
{
	const char	*err[] = {
		"unknown error",
		"Usage: wolf3d data_file",
		"Unable to open data_file",
		"Unable to read data_file",
		"Unable to set player position",
		"Error: no space left",
		"Unable to initialize SDL",
		"Unable to create window",
		"Unable to create renderder"
	};

	write(2, err[no], ft_strlen(err[no]));
	write(2, "\n", 1);
	return (no);
}
