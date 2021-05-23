/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:48:27 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/23 18:41:01 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag(t_arg *arg)
{
	const char	*format;
	char		c;

	arg->flags = 0;
	c = arg->format[(arg->i)];
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
		return (0);
	arg->i++;
	return (1);
}

int	ft_get_number(char *format, int *i)
{
	int	c;

	c = 0;
	while (ft_isdigit(format[*i]))
	{
		c *= 10;
		c += (int)(c - 48);
		*i++;
	}
	return (c);
}

static int	ft_check_width(t_arg *arg)
{
	char	c;
	int		nbr;

	nbr = 0;
	arg->width = 0;
	c = arg->format[(arg->i)];
	if (c == '0')
		return (-1);
	nbr = ft_get_number(arg->format, &(arg->i));
	if (nbr > 0)
		arg->width = nbr;
	if (arg->format[(arg->i)] == '*')
	{
		arg->width = -1;
		arg->i++;
	}
	if (((arg->width) == -1) && (nbr > 0))
		return (-1);
	if (arg->width != 0)
		return (1);
	return (0);
}

int	ft_parse_format(t_arg *arg)
{
	const char	*format;

	format = arg->format;
	while (format[arg->i])
	{
		if (ft_check_flag(arg) == -1)
			return (-1);
		if (ft_check_width(arg) == -1)
			return (-1);
		arg->i++;
	}
	return (arg->written);
}
