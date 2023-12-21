/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:52:08 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/30 15:02:28 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_convert(const char *str, int i, va_list args, int *error);
size_t	ft_print_b(unsigned int n, char *base, long base_size, int *error);
size_t	ft_putnbr(int n, size_t count, unsigned int sign, int *error);
size_t	ft_putstr(char *s, int *error);
size_t	ft_putchar(char c, int *error);
size_t	ft_print_ptr(unsigned long ptr, size_t count, int *error);
size_t	ft_print_address(unsigned long n, size_t count, char *base, int *error);

#endif
