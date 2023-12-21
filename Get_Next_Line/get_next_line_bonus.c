/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:28 by bhumeau           #+#    #+#             */
/*   Updated: 2023/12/19 14:51:44 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	ft_is_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_n(char const *s1, char const *s2, int is_n, size_t i)
{
	char	*ptr_dest;
	int		len_s2;
	int		len;

	len_s2 = ft_strlen(s2);
	if (len_s2 > is_n && is_n > 0)
		len_s2 = is_n;
	is_n = 0;
	len = (ft_strlen(s1) + len_s2);
	ptr_dest = malloc(sizeof(char) * (len + 1));
	if (ptr_dest == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		ptr_dest[i] = s1[i];
		i++;
	}
	while (len_s2--)
	{
		ptr_dest[i + is_n] = s2[is_n];
		is_n++;
	}
	ptr_dest[i + is_n] = '\0';
	free((char *)s1);
	return (ptr_dest);
}

char	*ft_strdup_n(const char *s, int is_n)
{
	char	*ptr;
	int		i;

	i = -1;
	if (is_n == -1)
		is_n = ft_strlen(s);
	ptr = malloc(sizeof(char) * (is_n + 1));
	if (ptr == NULL)
		return (NULL);
	while (++i < is_n)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

void	ft_clean(char *buffer, int is_n)
{
	int	i;

	i = 0;
	while (is_n + i < BUFFER_SIZE)
	{
		buffer[i] = buffer[i + is_n + 1];
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[1006][BUFFER_SIZE + 1];
	char		*result;
	int			read_value;
	int			is_n;

	result = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) == -1)
		return (NULL);
	read_value = ft_buffer_0(buffer[fd], fd, &is_n);
	if (is_n == -1 && read_value > 0)
		result = ft_strdup_n(buffer[fd], is_n);
	while (read_value > 0 && is_n == -1)
	{
		read_value = ft_while_is_n(fd, buffer[fd], &is_n);
		if (is_n == -1)
			result = ft_strjoin_n(result, buffer[fd], is_n, 0);
	}
	if (is_n >= 0 && read_value > 0)
	{
		result = ft_strjoin_n(result, buffer[fd], is_n + 1, 0);
		ft_clean(buffer[fd], is_n);
	}
	if (read_value == 0 && is_n >= 0)
		result = NULL;
	return (result);
}
