/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:10:48 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 17:05:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char *av[])
{
	t_engine	data;
	t_error		err;

	if (ac != 2)
		return (ft_perror(EUSAGE));
	if ((err = engine_start(&data, av[1])))
		return (ft_perror(err));
	game(&data);
	engine_stop(data);
	return (0);
}
