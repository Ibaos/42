/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:29 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 15:46:45 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static size_t	ft_calc_size(size_t nbr, int minus)
{
	size_t	count;

	count = 0;
	if (minus == -1)
		count++;
	while (nbr > 9)
	{
		nbr = (nbr / 10);
		count++;
	}
	count++;
	return (count);
}

static char	*ft_calc(size_t nbr, int minus, char *result,
size_t size)
{
	result[size] = '\0';
	while (nbr > 9)
	{
		result[--size] = ((nbr % 10) + 48);
		nbr = (nbr / 10);
	}
	result[--size] = (nbr + 48);
	if (minus < 0)
		result[--size] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	size_t			nbr;
	size_t			size;
	char			*result;
	int				minus;

	nbr = n;
	minus = 1;
	if (n < 0)
	{
		minus = (-1);
		nbr = nbr * (-1);
	}
	size = ft_calc_size(nbr, minus);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_calc(nbr, minus, result, size);
	return (result);
}
