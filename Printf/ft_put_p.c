/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:47:20 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/30 15:02:43 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_address(unsigned long n, size_t count, char *base, int *error)
{
	if (n > 15 && *error == 1)
	{
		count += ft_print_address(n / 16, count, base, error);
		n = n % 16;
	}
	if (n <= 15 && *error == 1)
		count += ft_putchar(base[n], error);
	return (count);
}

size_t	ft_print_ptr(unsigned long n, size_t count, int *error)
{
	if (n)
	{
		count += ft_putstr("0x", error);
		count += ft_print_address(n, 0, "0123456789abcdef", error);
		return (count);
	}
	else
		return (ft_putstr("(nil)", error));
}
