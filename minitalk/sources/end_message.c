/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:16:31 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/26 17:16:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	end_message(char *g_buffer, size_t *count, int *pid, int *check_pid)
{
	if (g_buffer[0] == 'e' && g_buffer[1] == 'x' && g_buffer[2] == 'i'
		&& g_buffer[3] == 't' && g_buffer[4] == '\0')
	{
		write(STDOUT_FILENO, g_buffer, ft_strlen(g_buffer));
		kill(*pid, SIGUSR2);
		free(g_buffer);
		exit(EXIT_SUCCESS);
	}
	*check_pid = 0;
	*count = 0;
	write(STDOUT_FILENO, g_buffer, ft_strlen(g_buffer));
	free(g_buffer);
	kill(*pid, SIGUSR2);
}
