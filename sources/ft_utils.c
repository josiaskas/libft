/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:16:54 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/25 17:44:47 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_make_zero_right(char *str, int width, int n)
{
	while ((width > 0) && (n > 0))
	{
		str[n--] = '0';
		width--;
	}
	return ;
}

void	ft_make_zero_left(char *str, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		str[i] = '0';
		i++;
	}
	return ;
}

void	ft_make_space_right(char *str, int width, int n)
{
	while ((width > 0) && (n > 0))
	{
		str[n--] = ' ';
		width--;
	}
	return ;
}

void	ft_make_space_left(char *str, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	return ;
}
