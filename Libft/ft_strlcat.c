/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:19:51 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:54:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;
	size_t	len_total;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	len_total = len_src + len_dst;
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (size + len_src);
	size -= len_dst;
	i = len_dst;
	j = 0;
	while (src[j] && size > 1)
	{
		dst[i++] = src[j++];
		size--;
	}
	dst[i] = '\0';
	return (len_total);
}

/*#include <stdio.h>
int	main(void)
{
	char	dest[] = "123";
	char	src[] = "456";
	unsigned int	size = 2;
	printf("%d\n", ft_strlcat(dest, src, size));
	printf ("%s\n",dest);
	return (0);
}*/
