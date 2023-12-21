/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:39:07 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/20 12:24:34 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	while (n--)
		if (*(ptr_s++) == (unsigned char)c)
			return (--ptr_s);
	return (0);
}

/*int	main(void)
{
	unsigned char	*s;
	unsigned char	text[] = "Voici le texte a trouver !";

	s = text;
	printf("%s", ft_memchr(s, 't', 17));
	return (0);
}*/
