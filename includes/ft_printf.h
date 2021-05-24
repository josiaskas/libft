/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:18:08 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/23 20:47:32 by jkasongo         ###   ########.fr       */
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
	char	flags;
	int		width;
	int		precison;
	char	specifier;
	int		written;
}	t_arg;

typedef int	(*t_parse_arg)(t_arg);

int	ft_printf(const char *s, ...);
int	ft_parse_format(t_arg *arg, va_list args);

#endif
