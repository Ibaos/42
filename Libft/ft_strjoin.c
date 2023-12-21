/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:08:16 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/16 15:57:18 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr_dest;
	size_t	len;

	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	ptr_dest = malloc(sizeof(char) * (len + 1));
	if (ptr_dest == NULL)
		return (NULL);
	while (*s1)
	{
		*ptr_dest = *s1;
		ptr_dest++;
		s1++;
	}
	while (*s2)
	{
		*ptr_dest = *s2;
		ptr_dest++;
		s2++;
	}
	*ptr_dest = '\0';
	return (ptr_dest - len);
}

/*#include <stdio.h>
int	main(void)
{
	char	pre[] = "Avant ! e";
	char	suf[] = "t apres !";
	printf("%s", ft_strjoin(pre, suf));
	return (0);
}*/
