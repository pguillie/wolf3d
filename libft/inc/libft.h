/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:27:45 by pguillie          #+#    #+#             */
/*   Updated: 2018/10/24 13:08:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strappend(char *str, const char *content);
char	*ft_strchr(const char *s, int c);
void	ft_strdel(char **as);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);

#endif
