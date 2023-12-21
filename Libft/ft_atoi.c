/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:55:49 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/20 12:18:13 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	size_t		i;
	long int	number;
	long int	number_cmp;

	sign = 1;
	i = 0;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
		if (nptr[i++] == 45)
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number_cmp = number * 10 + nptr[i++] - 48;
		if (number_cmp < number && sign > 0)
			return (-1);
		if (number_cmp < number && sign < 0)
			return (0);
		number = number_cmp;
	}
	return (number * sign);
}

/*int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("Ecrire 1 seul nombre");
		return (0);
	}
	printf("ft_atoi = %d\n",ft_atoi(argv[1]));
	printf("atoi = %d\n", atoi(argv[1]));
	return (0);
}*/
