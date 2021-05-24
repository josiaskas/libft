/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:28 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/23 20:49:39 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	loop_format(const char *format, t_arg *arg, va_list args)
{
	int	written;

	while (format[arg->cursor] != 0)
	{
		if (format[arg->cursor] == '%')
		{
			if (ft_parse_format(arg, args))
				written += arg->written;
			else
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[arg->cursor], STDOUT_FILENO);
			written++;
		}
		arg->cursor++;
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	int		total_written;
	t_arg	*arg;
	va_list	args;

	arg = (t_arg*)ft_calloc(1, sizeof(t_arg));
	va_start(args, format);
	total_written = 0;
	arg->format = format;
	arg->cursor = 0;
	total_written = loop_format(format, arg, args);
	va_end(args);
	if (total_written < 0)
		return (0);
	return (total_written);
}
