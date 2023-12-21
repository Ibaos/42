/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_csdiux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:49:31 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/30 15:02:35 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c, int *error)
{
	*error = write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s, int *error)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (ft_putstr("(null)", error));
	while (s[count] && *error == 1)
		ft_putchar(s[count++], error);
	return (count);
}

size_t	ft_putnbr(int n, size_t count, unsigned int sign, int *error)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", error));
	if (n < 0)
	{
		sign = ft_putchar('-', error);
		n = n * (-1);
	}
	if (n > 9 && *error == 1)
	{
		count += ft_putnbr(n / 10, count, 0, error);
		n = n % 10;
	}
	if (n <= 9 && *error == 1)
	{
		n = n + '0';
		count += ft_putchar(n, error);
	}
	return (count + sign);
}

size_t	ft_print_b(unsigned int n, char *base, long base_size, int *error)
{
	size_t	count;

	count = 0;
	if (n < 0)
		n = 4294967296 + n;
	if (n > (base_size - 1) && *error == 1)
	{
		count += ft_print_b(n / base_size, base, base_size, error);
		n = n % base_size;
	}
	if (n <= (base_size - 1) && *error == 1)
	{
		ft_putchar(base[n], error);
		count++;
	}
	return (count);
}
