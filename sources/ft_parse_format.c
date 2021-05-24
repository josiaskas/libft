/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:48:27 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/23 21:06:23 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_flag(t_arg *arg)
{
	const char	*format;
	char		c;

	arg->flags = 0;
	c = arg->format[(arg->cursor)];
	if (c == '-')
		arg->flags = '-';
	else if (c == '+')
		arg->flags = '+';
	else if (c == ' ')
		arg->flags = ' ';
	else if (c == '#')
		arg->flags = '#';
	else if (c == '0')
		arg->flags = '0';
	else
		return ;
	arg->cursor++;
}

static int	ft_check_width(t_arg *arg, va_list args)
{
	char	c;
	int		nbr;

	nbr = 0;
	arg->width = 0;
	c = arg->format[(arg->cursor)];
	if (c == '*')
	{
		arg->width = va_arg(args, int);
		arg->cursor++;
	}
	if (c >= '1' && c <= '9')
	{
		nbr = ft_atoi(&(arg->format[arg->cursor]));
		arg->width = nbr;
	}
	if (c == '0')
		return (0);
	return (1);
}

int	ft_parse_format(t_arg *arg, va_list args)
{
	const char	*format;

	format = arg->format;
	while (format[arg->cursor])
	{
		ft_check_flag(arg);
		if (!ft_check_width(arg, args))
			return (0);
		arg->cursor++;
	}
	return (arg->written);
}
