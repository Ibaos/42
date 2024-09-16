/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:23:45 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/22 18:59:21 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_alloc(const char *s, char c, size_t current_word)
{
	char		*word;
	size_t		i;
	size_t		start;
	size_t		end;

	i = 0;
	while (current_word--)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
	}
	end = i;
	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		count_word;
	size_t		current_word;

	current_word = 0;
	count_word = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (count_word + 1));
	if (result == NULL)
		return (NULL);
	while (current_word < count_word)
	{
		result[current_word] = ft_alloc(s, c, current_word + 1);
		if (result[current_word] == NULL)
		{
			while (--current_word + 1)
				free(result[current_word]);
			free(result);
			return (NULL);
		}
		current_word++;
	}
	result[current_word] = NULL;
	return (result);
}
