/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:55:38 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/14 19:00:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_perror(t_error no)
{
	const char	*err[] = {
		"unknown error",
		"Usage: wolf3d <data_file>",
		"Error: Unable to open data_file",
		"Error: Unable to read data_file",
		"Error: Unable to set player position",
		"Error: No space left",
		"Error: Unable to initialize SDL",
		"Error: Unable to create window",
		"Error: Unable to create renderder",
		"Warning: Some textures haven't been properly loaded"
	};

	write(2, err[no], ft_strlen(err[no]));
	write(2, "\n", 1);
	return (no);
}
