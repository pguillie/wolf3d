/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnm_alloc_row.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:00:58 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/09 19:01:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pnm.h"

uint16_t	**ft_pnm_alloc_row(t_pnm data)
{
	uint16_t	**row;
	int			i;

	if ((row = (uint16_t **)malloc(sizeof(uint16_t *) * data.width)))
	{
		i = 0;
		while (i < data.width)
		{
			row[i] = ((uint16_t *)malloc(sizeof(uint16_t) * data.depth));
			if (row[i] == NULL)
			{
				while (i--)
					free(row[i]);
				free(row);
				row = NULL;
				break ;
			}
			i++;
		}
	}
	return (row);
}
