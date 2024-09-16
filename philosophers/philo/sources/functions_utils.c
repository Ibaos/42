/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:49:17 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/08 15:38:48 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

static int	check(const char *nptr, int i)
{
	if (nptr[i] == '\0')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	size_t		i;
	long int	number;
	long int	number_cmp;

	sign = 1;
	i = 0;
	number = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number_cmp = number * 10 + nptr[i++] - '0';
		if (number_cmp > 2147483647 && sign > 0)
			return (0);
		if (number_cmp > 2147483648 && sign < 0)
			return (0);
		number = number_cmp;
	}
	if (check(nptr, i))
		return (0);
	return (number * sign);
}
