/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:59:34 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/15 19:32:30 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	size_t	i_len;

	if (little[0] == '\0')
		return ((char *)big);
	i_big = 0;
	while (big[i_big] && (i_big + 1) <= len)
	{
		i_little = 0;
		i_len = i_big + 1;
		while (big[i_big + i_little] == little[i_little] && i_len <= len)
		{
			if (little[i_little + 1] == '\0')
				return (((char *)big + i_big));
			i_little++;
			i_len++;
		}
		i_big++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%s", ft_strnstr("abc", "a", 1));
	return (0);
}*/
