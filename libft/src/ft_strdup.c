/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:09:25 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/26 12:24:30 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s[len];
	return (str);
}
