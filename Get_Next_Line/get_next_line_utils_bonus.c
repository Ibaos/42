/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:38 by bhumeau           #+#    #+#             */
/*   Updated: 2023/12/19 14:51:58 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_buffer_0(char *buffer, int fd, int *is_n)
{
	int	read_value;

	read_value = 1;
	if (buffer[0] == '\0')
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		buffer[read_value] = '\0';
	}
	*is_n = ft_is_n(buffer);
	return (read_value);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_while_is_n(int fd, char *buffer, int *is_n)
{
	int	read_value;

	read_value = read(fd, buffer, BUFFER_SIZE);
	buffer[read_value] = '\0';
	*is_n = ft_is_n(buffer);
	return (read_value);
}
