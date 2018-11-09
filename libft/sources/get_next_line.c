/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:32:32 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/26 12:33:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnapp(char **str, char *to_add, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(*str);
	if ((res = (char *)malloc(len + n + 1)) == NULL)
		return (NULL);
	res[len + n] = '\0';
	while (n--)
		res[len + n] = to_add[n];
	while (len--)
		res[len] = (*str)[len];
	if (*str)
		free(*str);
	*str = res;
	return (res);
}

int			get_next_line(int fd, char **line)
{
	static char	*s;
	char		buff[BUFF_SIZE];
	char		*nl;
	size_t		c;

	if (!line || fd < 0)
		return (-1);
	c = BUFF_SIZE;
	while ((nl = ft_strchr(s, '\n')) == NULL && c == BUFF_SIZE)
	{
		ft_memset(buff, 0, BUFF_SIZE);
		if ((c = read(fd, buff, BUFF_SIZE)))
		{
			if (ft_strnapp(&s, buff, c) == NULL)
				return (-1);
		}
	}
	if (nl != NULL)
	{
		*line = ft_strndup(s, (size_t)nl - (size_t)s);
		ft_memmove(s, nl + 1, ft_strlen(nl));
		return (1);
	}
	*line = ft_strdup(s);
	free(s);
	return (0);
}
