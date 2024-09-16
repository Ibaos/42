/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:52:35 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/18 14:52:37 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_50(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);
char	*message_first_letter(char letter, char *g_buffer, char *array,
			int pid);
void	end_message(char *g_buffer, size_t *count, int *pid, int *check_pid);
