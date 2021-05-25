/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:44:37 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/25 13:23:43 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//[0-9] number or * (value inside the args)]
void	ft_parse_precision(t_arg *arg)
{
	int		precision ;
	char	c;

	precision = 0;
	if ((arg->format[arg->cursor]) != '.')
		return ;
	arg->cursor++;
	if ((arg->format[arg->cursor]) == '*')
	{
		arg->max_precision = va_arg(arg->args, int);
		arg->part[2] = 1;
		arg->cursor++;
		return ;
	}
	c = arg->format[arg->cursor];
	while ((c >= '0') && (c <= '9'))
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
