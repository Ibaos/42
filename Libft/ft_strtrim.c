/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:29:36 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:58:34 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (set[k])
	{
		if (s1[i] == set[k])
		{
			i++;
			k = 0;
		}
		if (s1[i] != set[k])
		{
			k++;
		}
	}
	if (s1[i] == '\0')
		return (0);
	return (i);
}

static int	ft_trim_end(char const *s1, char const *set)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (s1[j])
	{
		j++;
	}
	j--;
	while (set[k])
	{
		if (s1[j] == set[k])
		{
			j--;
			k = 0;
		}
		if (s1[j] != set[k])
		{
			k++;
		}
	}
	j++;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		i;
	size_t		j;
	size_t		k;

	k = 0;
	i = ft_trim_start(s1, set);
	j = ft_trim_end(s1, set);
	result = malloc(sizeof(char) * ((j - i + 1)));
	if (result == NULL)
		return (NULL);
	while (i + k < j)
	{
		result[k] = s1[i + k];
		k++;
	}
	result[k] = '\0';
	return (result);
}

/*int	main(void)
{
	char	text[] = "   ";

	printf("%s/fin", ft_strtrim(text, " "));
	return (0);
}*/
