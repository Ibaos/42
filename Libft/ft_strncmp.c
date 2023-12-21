/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:32:08 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:56:00 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}

/*int	main(void)
{
	char c1 = 'd';
	char c2 = '\3';
	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
	printf("c1 = %d et c2 = %d\n", c1, c2);
	return (0);
}*/
