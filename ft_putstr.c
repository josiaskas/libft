/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:54:32 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/11 14:14:06 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr(const char *s, const int fd)
{
	size_t	len;
	ssize_t	nb_byte;

	nb_byte = 0;
	if (!s)
		return (-1);
	len = ft_strlen(s);
	nb_byte = write(fd, s, len);
	return (nb_byte);
}
