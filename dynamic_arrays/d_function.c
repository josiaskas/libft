/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:35:23 by jkasongo          #+#    #+#             */
/*   Updated: 2022/04/08 21:46:31 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dynamic_arrays.h"

void *ft_del_elem(t_array *array, size_t i)
{
	t_array_node	*before_node;
	t_array_node	*node;
	t_array_node	*next_node;
	void			*content;

	if (array == 0)
		return (0);
	if (i >= array->length)
		return (0);
	content = 0;
	if ((array->length == 1) || (i == 0) || (i == (array->length - 1)))
		content = ft_pop(array);
	else if (i >= 1)
	{
		node = ft_get_array_node(array, i);
		next_node = ft_get_array_node(array, i + 1);
		content = node->content;
		if (node == array->head)
			array->head = next_node;
		else
		{
			before_node = ft_get_array_node(array, i - 1);
			before_node->next = next_node;
		}
		free(node);
		array->length--;
	}
	return (content);
}
