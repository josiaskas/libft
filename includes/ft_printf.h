/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/24 17:20:58 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# include "../libft/libft.h"
typedef struct s_arg
{
	char	*format;
	int		cursor;
	char	part[4];
	char	flag;
	int		min_width;
	int		max_precision;
	char	arg_type;
	int		written;
	va_list args;
}	t_arg;

int		ft_printf(const char *format, ...);
int		ft_parse_format(t_arg *arg, va_list args);
void	ft_parse_flag(t_arg *arg);
void	ft_parse_width(t_arg *arg, va_list args);
void	ft_parse_precision(t_arg *arg, va_list args);
#endif
