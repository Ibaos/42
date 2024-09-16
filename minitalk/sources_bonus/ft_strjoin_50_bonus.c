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

#include "../includes/minitalk_bonus.h"

char	*ft_strjoin_50(char const *s1, char const *s2)
{
	char	*ptr_dest;
	char	*save;
	size_t	len;
	size_t	i;

	save = (char *)s1;
	len = (ft_strlen((char *)s1) + 50);
	ptr_dest = malloc(sizeof(char) * (len + 1));
	if (ptr_dest == NULL)
	{
		free(save);
		return (NULL);
	}
	while (*s1)
		*ptr_dest++ = *s1++;
	i = 0;
	while (i++ < 50)
	{
		*ptr_dest = *s2;
		ptr_dest++;
		s2++;
	}
	*ptr_dest = '\0';
	free(save);
	return (ptr_dest - len);
}
