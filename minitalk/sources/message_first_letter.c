/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_first_letter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:44:39 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/27 15:44:41 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*message_first_letter(char letter, char *g_buffer, char *array, int pid)
{
	g_buffer = malloc(sizeof(char) * 50);
	if (g_buffer == NULL)
	{
		kill(pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
	ft_memset(g_buffer, '\0', 50);
	ft_memset(array, '\0', 50);
	g_buffer[0] = letter;
	return (g_buffer);
}
