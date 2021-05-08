/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:52:55 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/08 19:59:25 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

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

static void	ft_splitter(char **words, char const *s, char c)
{
	size_t	nbr_words;
	size_t	i;

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
}

char	**ft_split(char const *s, char c)
{
	size_t	nbr_words;
	char	**words;

	if (!s || !*s)
	{
		words = (char **)malloc(sizeof(char *) * 1);
		if (!words)
			return (0);
		*words = (void *)0;
		return (words);
	}
	nbr_words = count_words(s, c) + 1;
	words = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!words)
		return (0);
	ft_splitter(words, s, c);
	return (words);
}
