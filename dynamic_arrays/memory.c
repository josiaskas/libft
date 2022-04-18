/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:44:41 by jkasongo          #+#    #+#             */
/*   Updated: 2022/04/18 18:00:24 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dynamic_arrays.h"

/*
 * Create a dynamic array (link list)
 * Return (void *) of the content
 */
t_array	*ft_new_array()
{
	t_array	*array;

	array = (t_array *)ft_calloc(1, sizeof(t_array));
	if (array == 0)
		return (0);
	array->length = 0;
	array->head = 0;
	array->bottom = 0;
	array->type = e_array_normal;
	return (array);
}

/*
 * Push element to the end of Array works on non dic
 * Return (bool) true if space was found and content added
 */
bool	ft_push(t_array *array, void *content)
{
	t_array_node	*node;

	if (!array || (array->type == e_array_dic))
		return (false);
	node = (t_array_node *)ft_calloc(1, sizeof(t_array_node));
	if (!node)
		return (false);
	node->content = content;
	if (array->length == 0)
	{
		array->head = node;
		array->bottom = node;
	}
	else
		array->bottom->next = node;
	array->length++;
	return (true);
}

/*
 * Push element to the beggin of Array works on non dic
 * Return (bool) true if space was found and content added
 */
bool	ft_unshift(t_array *array, void *content)
{
	t_array_node *node;

	if (!array || (array->type == e_array_dic))
		return (false);
	node = (t_array_node *)ft_calloc(1, sizeof(t_array_node));
	if (!node)
		return (false);
	node->content = content;
	if (array->length == 0)
	{
		array->head = node;
		array->bottom = node;
	}
	else
	{
		node->next = array->head;
		array->head = node;
	}
	array->length++;
	return (true);
}

/*
* Pop the last element in the array
* Return (void *) of the content
*/
void	*ft_pop(t_array *array)
{
	t_array_node	*node;
	void			*content;

	if (!array)
		return (0);
	if (!array->length)
		return (0);
	content = 0;
	node = array->bottom;
	if (array->length == 1)
	{
		content = node->content;
		array->bottom = 0;
		array->head = 0;
	}
	else if (array->length > 1)
	{
		content = node->content;
		array->bottom = ft_get_array_node(array, (array->length - 1));
	}
	array->length--;
	free(node);
	return (content);
}

/*
 * Free Array and content inside
 */
void	ft_free_array(t_array *array)
{
	void	*content;

	if (!array)
		return;
	while (array->length)
	{
		content = ft_pop(array);
		free(content);
	}
	free(array);
	array = NULL;
	return;
}
