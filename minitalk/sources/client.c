/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:52:02 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/18 14:52:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_next;

void	check_message_success(int len, int count)
{
	static int	message_len;

	if (len > 0)
		message_len = len;
	else if (count < (message_len - 1))
	{
		write(STDERR_FILENO, "Message not successfully transmitted!\n", 38);
		exit(EXIT_FAILURE);
	}
	else
		write(STDOUT_FILENO, "Received!\n", 10);
}

void	signal_handler(int sig_num, siginfo_t *siginfo, void *context)
{
	static int	count;

	g_next = 1;
	if (sig_num == SIGUSR2)
	{
		check_message_success(0, count / 8);
		exit(EXIT_SUCCESS);
	}
	count ++;
	(void)siginfo;
	(void)context;
}

void	str_to_bit(char *message, int pid)
{
	int		len;
	int		i;
	int		j;
	char	tmp;

	i = 0;
	len = ft_strlen(message);
	check_message_success(len, 0);
	while (i <= len)
	{
		j = 7;
		tmp = message[i];
		while (j >= 0)
		{
			g_next = 0;
			if (tmp >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			while (!g_next)
				;
		}
		i++;
	}
}

bool	checks(int argc, int pid, char *message)
{
	if (argc != 3)
		return (write(STDERR_FILENO, "Invalid number of arguments!\n", 29));
	if (message[0] == '\0')
		return (write(STDERR_FILENO, "Empty message!\n", 15));
	if (pid <= 0 || kill(pid, 0) < 0)
		return (write(STDERR_FILENO, "PID is incorrect!\n", 19));
	return (0);
}

int	main(int argc, char **argv)
{
	char				*message;
	int					pid;
	struct sigaction	act;
	sigset_t			mask;

	message = argv[1];
	pid = 0;
	if (argv[2])
		pid = ft_atoi(argv[2]);
	if (checks(argc, pid, message))
		return (0);
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
	str_to_bit(message, pid);
	while (1)
		;
	return (0);
}
