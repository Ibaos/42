/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:38:34 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:25:56 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (n == 0 || (ptr_src == NULL && ptr_dest == NULL))
		return (dest);
	while (n--)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
	}
	return (dest);
}

/*int	main(void)
{
	char	*src;
	char	*dest;
	char	text_src[] = "";
	char	text_dest[] = "segfaulter tu dois";
	size_t	size = 17;

	src = text_src;
	dest = text_dest;
	printf("src = %s\n", src);
	printf("dest = %s\n", dest);
	printf("return = %s\n", ft_memcpy(dest, src, size));
	printf("test franc %s\n",ft_memcpy(((void*)0), ((void*)0), 3));

	return (0);
}*/
