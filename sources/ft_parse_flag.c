/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:54:46 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/24 15:23:53 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flag(t_arg *arg)
{
	char	c;

	c = arg->format[arg->cursor];
	if ((c == '-') || (c == '+') || (c == ' ') || (c == '#') || (c == '0'))
	{
		arg->part[0] = 1;
		arg->flag = c;
		arg->cursor++;
	}
	return ;
}
