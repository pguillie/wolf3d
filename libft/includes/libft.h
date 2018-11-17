/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:27:45 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/17 20:17:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *s, size_t n);

#endif
