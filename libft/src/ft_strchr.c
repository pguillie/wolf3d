/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:19:29 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/26 09:21:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			return ((char*)s + i);
	}
	return (NULL);
}
