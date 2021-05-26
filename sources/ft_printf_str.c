/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:09 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/26 19:00:27 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_with_zero(t_arg *arg, int width)
{

}

static void	ft_print_left_aligned(t_arg *arg, int width)
{

}

static void	print_special(char *flag, int len, char *str, t_arg *arg)
{
	int		width;

	width = len;
	if (arg->min_width > len)
		width = arg->min_width;
	if (flag[e_minus] && (width > len))
	{
		ft_print_left_aligned(arg, str, width);
		return ;
	}
	if (flag[e_zero])
	{
		ft_print_left_aligned(arg, str, width);
		return ;
	}
}

void	ft_printf_str(t_arg *arg)
{
	int		len;
	char	*flag;
	char	*str;
	char	*null;

	str = va_arg(arg->args, char *);
	len = ft_strlen(str);
	null = "(null)";
	if (!str)
		str = null;
	if ((arg->part[0]) || (arg->min_width > len))
		print_special(arg->flag, len, str, arg);
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		arg->written = len;
	}
	return ;
}
