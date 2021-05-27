/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:41:20 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/27 17:21:17 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_precision_spaces(char *str, int precision, int len, t_arg *arg)
{
	char	*cpy;
	int		diff;

	diff = precision - len;
	cpy = ft_calloc(1, (precision + 1));
	if (diff > 0)
		cpy = ft_memset(cpy, ' ', diff);
	else
		diff = 0;
	if (arg->part[1] && (arg->min_width < 0))
		diff = 0;
	if (!arg->part[1])
		diff = 0;
	ft_strlcpy((cpy + diff), str, (precision +1));
	return (cpy);
}
