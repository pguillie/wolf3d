/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_free_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:07:24 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/08 16:47:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

void	ft_pnm_free_row(uint16_t **row, t_pnm data)
{
	int	i;

	i = 0;
	while (i < data.width)
		free(row[i++]);
	free(row);
}
