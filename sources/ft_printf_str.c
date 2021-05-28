/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:09 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/28 14:54:09 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_with_zero(t_arg *arg, char *str, int len)
{
	int	width;

	width = 0;
	if (arg->part[1])
		width = arg->min_width;
	if (width < 0)
		width *= -1;
	arg->written = 0;
	while (width > len)
	{
		write(STDOUT_FILENO, "0", 1);
		arg->written++;
		width--;
	}
	arg->written += len;
	ft_putstr_fd(str, STDOUT_FILENO);
}

static void	ft_print_right_aligned(t_arg *arg, char *str, int len)
{
	int	width;

	width = 0;
	if (arg->part[1])
		width = arg->min_width;
	if (width < 0)
		width *= -1;
	arg->written = 0;
	while (width > len)
	{
		write(STDOUT_FILENO, " ", 1);
		arg->written++;
		width--;
	}
	arg->written += len;
	ft_putstr_fd(str, STDOUT_FILENO);
}

static void	ft_print_left_aligned(t_arg *arg, char *str, int len)
{
	int	width;

	arg->written = 0;
	arg->written += len;
	ft_putstr_fd(str, STDOUT_FILENO);
	width = 0;
	if (arg->part[1])
		width = arg->min_width;
	if (width < 0)
		width *= -1;
	while (width > len)
	{
		write(STDOUT_FILENO, " ", 1);
		arg->written++;
		width--;
	}
}

static void	print_special(char *flag, int len, char *str, t_arg *arg)
{
	char	*str_part;

	arg->written = 0;
	str_part = 0;
	if (arg->part[2])
	{
		str_part = ft_precision_spaces(str, arg->max_precision, len, arg);
		len = ft_strlen(str_part);
	}
	else
		str_part = ft_strndup(str, len);
	if (flag[e_minus])
		ft_print_left_aligned(arg, str_part, len);
	else if (flag[e_zero])
		ft_print_with_zero(arg, str_part, len);
	else if (arg->part[1] && (arg->min_width < 0))
		ft_print_left_aligned(arg, str_part, len);
	else
		ft_print_right_aligned(arg, str_part, len);
	free(str_part);
	return ;
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
		len = 6;
	}
	if (arg->part[0] || arg->part[1] || arg->part[2])
		print_special(arg->flag, len, str, arg);
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		arg->written = len;
	}
	return ;
}
