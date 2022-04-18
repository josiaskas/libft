/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:17 by jkasongo          #+#    #+#             */
/*   Updated: 2022/04/18 17:58:53 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dynamic_arrays.h"

/*
 * Create a dynamic dictionary
 * Return (void *) of the content
 */
t_array	*ft_new_dic()
{
	t_array	*array;

	array = (t_array *)ft_calloc(1, sizeof(t_array));
	if (array == 0)
		return (0);
	array->length = 0;
	array->head = 0;
	array->bottom = 0;
	array->type = e_array_dic;
	return (array);
}

/*
 * Get (t_dic_node *) elem form disctionary if key match
 * Return a key (char *) and (void *) content
 */
t_dic_node	*ft_elem_dic(t_array *array, char *key)
{
	size_t		i;
	t_dic_node	*node_key;
	size_t		len;
	char		*key_i;

	i = 0;
	if (array->type != e_array_dic)
		return (0);
	len = ft_strlen(key);
	while ((i < array->length) && (len > 0))
	{
		node_key = (t_dic_node *)ft_get_elem(array, i);
		if (node_key == 0)
			break;
		key_i = node_key->key;
		if ((ft_strncmp(key_i, key, len) == 0) && (len == ft_strlen(key_i)))
			return (node_key);
		i++;
	}
	return (0);
}


/*
 * Push element to the end of Array works on non dic
 * Return (bool) true if space was found and content added
 * Return false if key already exist or no space
 * saved as ["key"] = void *content
 */
bool	ft_push_to_dic(t_array *array, char *key, void *content)
{
	t_dic_node		*node_key;
	t_array_node	*node_array;

	if (!array || (array->type != e_array_dic))
		return (false);
	if (ft_elem_dic(array, key) != 0)
		return(false);
	node_key = (t_dic_node *)ft_calloc(1, sizeof(t_dic_node));
	node_array = (t_array_node *)ft_calloc(1, sizeof(t_array_node));
	if (!node_array || !node_key)
		return (false);
	node_key->content = content;
	node_key->key = key;
	node_array->content = node_key;
	if (array->length == 0)
	{
		array->head = node_array;
		array->bottom = node_array;
	}
	else
		array->bottom->next = node_array;
	array->length++;
	return (true);
}

/*
 * Free Dictionary and content inside
 */
void	ft_free_dic(t_array *array)
{
	void		*content;
	t_dic_node	*node;

	if (!array)
		return;
	while (array->length)
	{
		node = (t_dic_node *)ft_pop(array);
		content = node->content;
		free(content);
		free(node);
	}
	free(array);
	array = 0;
	return;
}

/*
 * Take a dictionary and apply the f function, wich return pointers to result
 * Return an array of size array->lengh contening pointers of f results
 * [void *p1, void *p2, ...]
 */
void	**ft_map_d(t_array *array, void *(*f)(void *c, char *key, int i))
{
	void			**results;
	size_t			i;
	t_array_node	*node;
	t_dic_node		*node_key;

	i = 0;
	if (!array)
		return (0);
	if (!array->length)
		return (0);
	node = array->head;
	results = ft_calloc(array->length, sizeof(void *));
	if (!results)
		return (0);
	while (i < array->length)
	{
		node_key = node->content;
		results[i] = f(node_key->content, node_key->key, i);
		node = node->next;
		i++;
	}
	return (results);
}
