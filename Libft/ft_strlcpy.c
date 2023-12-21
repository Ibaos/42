/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:30:53 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/15 15:40:20 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	int	i = 0;

	char dst[15] = "coucou";
	char src[] = "lorem ipsum dolor sit amet";

	printf("%zu\n", ft_strlcpy(dst, src, 15));
	while (dst[i])
	{
		printf("%c", dst[i]);
		i++;
	}
	return (0);
}*/
