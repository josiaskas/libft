/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:17:31 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/13 16:33:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_p;

	if ((size == 0) || (count == 0))
		return (0);
	heap_p = malloc(count * size);
	if (!heap_p)
		return (0);
	ft_bzero(heap_p, count);
	return (heap_p);
}
