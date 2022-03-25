/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:24:43 by jkasongo          #+#    #+#             */
/*   Updated: 2022/03/24 23:53:37 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dynamic_arrays.h"
/*
 * Get the node on that index
 * Return (NULL) if no array or i bigger than length
 */
t_array_node	*ft_get_array_node(t_array *array, size_t i)
{
	size_t			j;
	t_array_node	*node;

	j = 0;
	node = array->head;
	if (array == 0)
		return (0);
	if (i >= array->length)
		return (0);
	while (i != j)
	{
		node = node->next;
		j++;
	}
	return (node);
}

void	*ft_get_elem(t_array *array, size_t index)
{
	void			*content;
	t_array_node	*node;

	content = 0;
	node = ft_get_array_node(array, index);
	if (node == 0)
		return (0);
	content = node->content;
	return (content);
}
