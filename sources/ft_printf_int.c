/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:51:04 by jkasongo          #+#    #+#             */
/*   Updated: 2021/06/04 23:46:39 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_options(char *flag, int len, char *str, t_arg *arg)
{
	if (flag[e_minus])
		ft_print_left_aligned_str(arg, str, len);
	else if (flag[e_zero])
		ft_print_with_zero_str(arg, str, len);
	else if (arg->part[1] && (arg->min_width < 0))
		ft_print_left_aligned_str(arg, str, len);
	else
		ft_print_right_aligned_str(arg, str, len);
}

static void	print_special(char *flag, int sign, char *str, t_arg *arg)
{
	char	*str_precised;
	char	*tmp;
	int		len;

	arg->written = 0;
	str_precised = 0;
	tmp = 0;
	len = ft_strlen(str);
	if (arg->part[2] && ((arg->max_precision > len)))
		str_precised = ft_precision_zeros(str, arg->max_precision, len);
	else
		str_precised = ft_strndup(str, len);
	if (sign == -1)
	{
		tmp = ft_strjoin("-", str_precised);
		free(str_precised);
		str_precised = tmp;
	}
	len = ft_strlen(str_precised);
	if ((len == 1) && (arg->max_precision == 0) && (str[0] == '0'))
		print_options(flag, 0, "", arg);
	else
		print_options(flag, len, str_precised, arg);
	free(str_precised);
	return ;
}

void	ft_printf_int(t_arg *arg)
{
	int		nbr;
	int		sign;
	char	*str;
	int		len;

	nbr = va_arg(arg->args, int);
	sign = 1;
	if (nbr < 0)
		sign = -1;
	str = ft_itoa_printf(nbr * sign);
	len = ft_strlen(str);
	if (arg->part[0] || arg->part[1] || arg->part[2])
		print_special(arg->flag, sign, str, arg);
	else
	{
		if (sign == -1)
		{
			len++;
			write(STDOUT_FILENO, "-", 1);
		}
		ft_putstr_fd(str, STDOUT_FILENO);
		arg->written = len;
	}
	free(str);
	return ;
}
