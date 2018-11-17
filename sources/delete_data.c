/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:31:55 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 23:50:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_data(t_engine data)
{
	int	i;

	i = 0;
	while (i < data.map.h)
		free(data.map.layout[i++]);
	if (i)
		free(data.map.layout);
}
