/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:28 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/24 17:22:05 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_format(t_arg *arg, va_list args)
{
	int	error;

	error = 0;
	ft_bzero(arg->part, 4);
	while (arg->format[arg->cursor])
	{
		if (arg->format[arg->cursor])
			ft_parse_flag(arg);
		if (arg->format[arg->cursor])
			ft_parse_width(arg, args);
		if ()
		{
			ft_parse_width(arg, args);
		}
		arg->cursor++;
	}
	return (error);
}

static int	loop_format(t_arg *arg, va_list args)
{
	int	written;

	while (arg->format[arg->cursor] != 0)
	{
		if (arg->format[arg->cursor] == '%')
		{
			if (ft_parse_format(arg, args))
				written += arg->written;
			else
				return (0);
		}
		else
		{
			ft_putchar_fd(arg->format[arg->cursor], STDOUT_FILENO);
			written++;
		}
		arg->cursor++;
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	int		total_written;
	va_list	args;
	t_arg	arg;

	va_start(arg.args, format);
	total_written = 0;
	arg.format = format;
	arg.cursor = 0;
	total_written = loop_format(&arg, args);
	va_end(arg.args);
	if (total_written < 0)
		return (0);
	return (total_written);
}
