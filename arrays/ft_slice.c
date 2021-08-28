/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:28:59 by jkasongo          #+#    #+#             */
/*   Updated: 2021/08/28 12:10:40 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/array_utils.h"

int	*ft_slice_int(const int original[], int begin, int end)
{
	unsigned int	size;
	int				i;
	int				j;
	int				*copy;

	size = end - begin;
	i = 0;
	j = 0;
	copy = NULL;
	if (size > 0)
	{
		copy = (int *)malloc(sizeof(int) * size);
		if (!copy)
			return (NULL);
		if (original)
		{
			while (original[i])
			{
				if ((i >= begin) && (i <= end))
					copy[j] = original[i];
				i++;
			}
		}
	}
	return (copy);
}
