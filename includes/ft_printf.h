/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/25 17:44:41 by jkasongo         ###   ########.fr       */
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
	const char	*format;
	int			cursor;
	int			cursor_arg;
	int			part[4];
	char		flag[4];
	int			min_width;
	int			max_precision;
	char		arg_type;
	int			written;
	va_list		args;
}	t_arg;

enum	e_flags
{
	e_minus,
	e_zero,
	e_space,
	e_plus,
};

int		ft_printf(const char *format, ...);
void	ft_parse_flag(t_arg *arg);
void	ft_parse_width(t_arg *arg);
void	ft_parse_precision(t_arg *arg);
void	ft_parse_arg_type(t_arg *arg);
void	ft_write_arg_data(t_arg *arg);
void	ft_printf_char(t_arg *arg);

void	ft_make_zero_right(char *str, int width, int n);
void	ft_make_zero_left(char *str, int width);
void	ft_make_space_right(char *str, int width, int n);
void	ft_make_space_left(char *str, int width);

#endif
