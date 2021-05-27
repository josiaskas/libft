/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:09 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/27 12:41:56 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_with_zero(t_arg *arg, char *str, int len, int width)
{
	arg->written = width;
	while (width > len)
	{
		write(STDOUT_FILENO, "0", 1);
		width--;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
}

static void	ft_print_rigth_aligned(t_arg *arg, char *str, int len, int width)
{
	arg->written = width;
	while (width > len)
	{
		write(STDOUT_FILENO, " ", 1);
		width--;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
}

static void	ft_print_left_aligned(t_arg *arg, char *str, int len, int width)
{
	arg->written = width;
	ft_putstr_fd(str, STDOUT_FILENO);
	width -= len;
	while (width > 0)
	{
		write(STDOUT_FILENO, " ", 1);
		width--;
	}
}

static void	print_special(char *flag, int len, char *str, t_arg *arg)
{
	int		width;

	width = len;
	if (arg->min_width > len)
		width = arg->min_width;
	if (flag[e_minus])
	{
		ft_print_left_aligned(arg, str, len, width);
		return ;
	}
	if (flag[e_zero])
	{
		ft_print_with_zero(arg, str, len, width);
		return ;
	}
	ft_print_rigth_aligned(arg, str, len, width);
}

void	ft_printf_str(t_arg *arg)
{
	int		len;
	char	*str;
	char	*null;

	str = va_arg(arg->args, char *);
	len = ft_strlen(str);
	null = "(null)";
	if (!str)
	{
		str = null;
		len = 7;
	}
	if ((arg->part[0]) || (arg->part[1]))
		print_special(arg->flag, len, str, arg);
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		arg->written = len;
	}
	return ;
}
