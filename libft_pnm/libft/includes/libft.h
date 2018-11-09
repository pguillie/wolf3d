/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:19:51 by pguillie          #+#    #+#             */
/*   Updated: 2018/11/07 21:29:57 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_isdigit(int c);
int		ft_isspace(int c);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

int		ft_putnbr_fd(int nbr, int fd);

#endif
