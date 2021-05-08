/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:52:55 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/08 19:18:03 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t count;
	int i;

	count = 0;
	i = 0;
	while (*s != 0)
	{
		if ((*s == c) && (i == 0))
			s++;
		if ((*s == c) && (i != 0))
		{
			count++;
			i = 0;
		}
		if ((*s != c))
			i++;
		s++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	size_t nbr_words;
	char **words;
	size_t i;

	if (!s || !*s)
		return (0);
	if (!(words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 2))))
		return (0);
	nbr_words = 0;
	i = 0;
	while ((*s) != 0)
	{
		if ((*s == c) && (i == 0))
			s++;
		if ((*s == c) && (i != 0))
		{
			words[nbr_words++] = ft_strndup((s - i), i);
			i = 0;
		}
		if ((*s != c))
			i++;
		s++;
	}
	if (i != 0)
		words[nbr_words++] = ft_strndup((s - i), i);
	words[nbr_words] = 0;
	return (words);
}
