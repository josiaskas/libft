/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:54:52 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/21 21:14:24 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		args;
	va_list	ap;


	va_start(ap, args);

	va_end(ap);
	return (args);
}
