/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:28 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/23 18:47:14 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	loop_format(const char *format, t_arg *arg)
{
	int	written;

	while (format[arg->i] != 0)
	{
		if (format[arg->i] == '%')
		{
			if (ft_parse_format(arg))
				written += arg->written;
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[arg->i], STDOUT_FILENO);
			written++;
		}
		arg->i++;
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	int		total_written;
	va_list	lst;
	t_arg	*arg;

	arg = (*t_arg)ft_calloc(1, sizeof(t_arg));
	va_start(lst, format);
	total_written = 0;
	arg->format = format;
	arg->i = 0;
	arg->arguments = lst;
	total_written = loop_format(format, arg);
	va_end(lst);
	if (total_written < 0)
		return (0);
	return (total_written);
}
