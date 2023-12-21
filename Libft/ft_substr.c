/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:48 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/17 11:38:57 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(unsigned int start, size_t len,
size_t len_max)
{
	char	*ptr_dest;

	if (start > len_max || len == 0)
		ptr_dest = malloc(sizeof(char) * 1);
	else if (len + start <= len_max)
		ptr_dest = malloc(sizeof(char) * (len + 1));
	else
		ptr_dest = malloc(sizeof(char) * ((len_max - start) + 1));
	if (ptr_dest == NULL)
		return (NULL);
	return (ptr_dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_dest;
	size_t	len_max;
	size_t	i;

	len_max = ft_strlen(s);
	ptr_dest = ft_check(start, len, len_max);
	if (ptr_dest == NULL)
		return (NULL);
	if (len_max == 0 || start > len_max || len <= 0)
	{
		ptr_dest[0] = '\0';
		return (ptr_dest);
	}
	i = 0;
	while (len > 0 && s[start] && start < len_max)
	{
		len--;
		ptr_dest[i++] = s[start++];
	}
	ptr_dest[i] = '\0';
	return ((char *)ptr_dest);
}

/*int	main(void)
{
	int	start = 0;
	int	len = 0;
	char	*ptr_text;
	char	text[] = "";
	ptr_text = text;
	printf("main = %s", ft_substr(ptr_text, start, len));
	return (0);
}*/
