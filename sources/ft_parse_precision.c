/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:44:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/24 15:58:49 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//[0-9] number or * (value inside the args)]
void	ft_parse_precision(t_arg *arg, va_list args)
{
	int		precision ;
	char	c;

	precision = 0;
	arg->part[2] = 0;
	arg->max_precision = 0;
	c = arg->format[arg->cursor];
	if ((c != '.') && (c != 0))
		return ;
	arg->cursor++;
	c = arg->format[arg->cursor];
	if ((c == '*') && ((c != 0)))
	{
		arg->max_precision = va_arg(args, int);
		arg->part[2] = 1;
		arg->cursor++;
		return ;
	}
	while ((c >= '0') && (c <= '9') && ((c != 0)))
	{
		precision = precision * 10;
		precision += (int)(c - 48);
		arg->part[2] = 1;
		arg->max_precision = precision;
		arg->cursor++;
		c = arg->format[arg->cursor];
	}
	return ;
}
