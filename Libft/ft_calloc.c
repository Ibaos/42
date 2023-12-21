/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:33:55 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/15 19:51:54 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (((nmemb * size) / size) != nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_calloc(8, 7));
	return (0);
}*/
