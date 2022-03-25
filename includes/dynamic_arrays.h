/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arrays.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:45:33 by jkasongo          #+#    #+#             */
/*   Updated: 2022/03/24 23:50:49 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARRAYS_H
# define DYNAMIC_ARRAYS_H

# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_array_node
{
	void				*content;
	struct s_array_node	*next;
}	t_array_node;

typedef struct s_array
{
	size_t			length;
	t_array_node	*head;
	t_array_node	*bottom;
}	t_array;

t_array			*ft_new_array();
bool			push(t_array *array, void *content);
bool			ft_unshift(t_array *array, void *content);
void			*pop(t_array *array);
void			ft_free_array(t_array *array);
t_array_node	*ft_get_array_node(t_array *array, size_t i);
void			*ft_get_elem(t_array *array, size_t index);
#endif
