/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:51:39 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/30 15:02:23 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(const char *str, int i, va_list args, int *error)
{
	size_t	count;

	count = 0;
	if (str[i] == 'c')
		count = ft_putchar((char)va_arg(args, int), error);
	else if (str[i] == 's')
		count = ft_putstr((char *)va_arg(args, const char *), error);
	else if (str[i] == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long), 0, error);
	else if (str[i] == 'd')
		count = ft_putnbr(va_arg(args, int), 0, 0, error);
	else if (str[i] == 'i')
		count = ft_putnbr(va_arg(args, int), 0, 0, error);
	else if (str[i] == 'u')
		count = ft_print_b(va_arg(args, unsigned int), "0123456789", 10, error);
	else if (str[i] == 'x')
		count = ft_print_b(va_arg(args, size_t), "0123456789abcdef", 16, error);
	else if (str[i] == 'X')
		count = ft_print_b(va_arg(args, size_t), "0123456789ABCDEF", 16, error);
	else if (str[i] == '%')
		count = ft_putchar('%', error);
	else
		*error = (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;
	int		*error;
	int		value_error;

	i = 0;
	value_error = 1;
	error = &value_error;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0' && *error == 1)
	{
		if (str[i] == '%' && str[i++])
			count += ft_convert(str, i++, args, error);
		else
			count += ft_putchar(str[i++], error);
	}
	va_end(args);
	if (*error == (-1))
		return (-1);
	return (count);
}
