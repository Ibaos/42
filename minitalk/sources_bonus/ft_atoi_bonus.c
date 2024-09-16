/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:55:49 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/11 16:45:51 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	check(const char *nptr, int i)
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
