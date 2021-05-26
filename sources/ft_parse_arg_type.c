/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:53:47 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/25 18:26:00 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_arg_type(t_arg *arg)
{
	char	c;

	c = arg->format[arg->cursor];
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X'))
	{
		arg->arg_type = c;
		arg->cursor++;
		arg->part[3] = 1;
	}
}

void	ft_write_arg_data(t_arg *arg)
{
	if (arg->arg_type == 'c')
		ft_printf_char(arg);
}