/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:54:23 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/25 13:17:34 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//[1-9 (only if flag specified first, not true) or * (value inside the args)]
void	ft_parse_width(t_arg *arg)
{
	int		width;
	char	c;

	width = 0;
	arg->part[1] = 0;
	c = arg->format[arg->cursor];
	if (c == '*')
	{
		arg->min_width = va_arg(arg->args, int);
		arg->part[1] = 1;
		arg->cursor++;
		return ;
	}
	while ((c >= '1') && (c <= '9'))
	{
		width = width * 10;
		width += (int)(c - 48);
		arg->part[1] = 1;
		arg->min_width = width;
		arg->cursor++;
		c = arg->format[arg->cursor];
	}
	return ;
}
