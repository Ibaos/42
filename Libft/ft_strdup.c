/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:04:40 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:52:14 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen((char *)s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (*s)
		*(ptr++) = *(s++);
	*ptr = '\0';
	return (ptr - len);
}

/*int	main(void)
{
	printf("%s", ft_strdup("Ceci est un test !"));
	return (0);
}*/
