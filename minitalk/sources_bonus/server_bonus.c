/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:52:08 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/18 14:52:11 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

char	*g_buffer;

void	char_to_str(char letter, int pid, int *check_pid)
{
	static size_t	count;
	static char		array[50];

	if (count == 0)
		g_buffer = message_first_letter(letter, g_buffer, array, pid);
	else if (count % 49 == 0)
	{
		g_buffer = ft_strjoin_50(g_buffer, array);
		if (g_buffer == NULL)
		{
			kill(pid, SIGUSR2);
			exit(EXIT_FAILURE);
		}
		g_buffer[count] = letter;
	}
	else if (letter == '\0')
		return (end_message(g_buffer, &count, &pid, check_pid));
	else
		g_buffer[count] = letter;
	count++;
}

void	bit_to_char(int i, int pid, int *check_pid)
{
	static char	letter;
	static int	count;

	letter |= i;
	if (count == 7)
	{
		count = 0;
		char_to_str(letter, pid, check_pid);
		letter = 0;
		kill(pid, SIGUSR1);
		return ;
	}
	else
		letter <<= 1;
	count++;
	kill(pid, SIGUSR1);
}

void	signal_handler(int sig_num, siginfo_t *siginfo, void *context)
{
	static int	check_pid;

	if (check_pid == 0)
		check_pid = siginfo->si_pid;
	if (check_pid != siginfo->si_pid)
	{
		kill(siginfo->si_pid, SIGUSR2);
		return ;
	}
	if (sig_num == SIGUSR1)
		bit_to_char(1, siginfo->si_pid, &check_pid);
	else if (sig_num == SIGUSR2)
		bit_to_char(0, siginfo->si_pid, &check_pid);
	(void)context;
}

bool	write_pid(int pid)
{
	char	*str;

	str = ft_itoa(pid);
	if (str == NULL)
		return (0);
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;
	sigset_t			mask;

	(void)argv;
	if (argc != 1)
		return (write(STDERR_FILENO, "Only 1 argument needed!\n", 24));
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	act.sa_mask = mask;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (write(STDERR_FILENO, "Error\n", 6));
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (write(STDERR_FILENO, "Error\n", 6));
	pid = getpid();
	if (!write_pid(pid))
		return (write(STDERR_FILENO, "Malloc failed!\n", 15));
	while (1)
		;
	return (0);
}
