/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:46:38 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/26 13:58:30 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_with_zero(t_arg *arg, int width)
{
	char	c;

	arg->written = width;
	while ((width - 1) > 0)
	{
		write(STDOUT_FILENO, "0", 1);
		width--;
	}
	c = va_arg(arg->args, int);
	write(STDOUT_FILENO, &c, 1);
	return ;
}

static void	ft_print_left_aligned(t_arg *arg, int width)
{
	char	c;

	c = va_arg(arg->args, int);
	write(STDOUT_FILENO, &c, 1);
	arg->written = width;
	while ((width - 1) > 0)
	{
		write(STDOUT_FILENO, " ", 1);
		width--;
	}
	return ;
}

static void	print_special(char *flag, int width, t_arg *arg)
{
	if (flag[e_minus])
	{
		ft_print_left_aligned(arg, width);
		return ;
	}
	if (flag[e_zero])
	{
		ft_print_with_zero(arg, width);
		return ;
	}
	return ;
}

void	ft_printf_char(t_arg *arg)
{
	int		width;
	char	*flag;
	char	c;

	width = 1;
	flag = arg->flag;
	if ((arg->part[1]) && (arg->min_width > 1))
		width = arg->min_width;
	if ((arg->part[0]) && (width > 1))
		print_special(arg->flag, width, arg);
	else
	{
		c = va_arg(arg->args, int);
		if (c == 0)
			write(STDOUT_FILENO, "\x00", 1);
		else
			write(STDOUT_FILENO, &c, 1);
		arg->written = 1;
	}
}
