/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:17:26 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/15 17:10:08 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	while (c >= 128)
		c = c - 128;
	str = 0;
	while (*s)
	{
		if (*s == c)
			str = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((char *)str);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strrchr("Je suis Benjamin !", 'a'));
	return (0);
}*/
