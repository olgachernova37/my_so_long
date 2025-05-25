/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:20:43 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/25 15:58:02 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum_of_printf;

	sum_of_printf = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			sum_of_printf += print_specifier(*(++format), args);
		}
		else
			sum_of_printf += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (sum_of_printf);
}

int	print_hexadecimal(unsigned int nbr, char symbol)
{
	int		count;
	char	*hex_base;

	count = 0;
	if (symbol == 'X')
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nbr == 0)
		return (print_char('0'));
	if (nbr >= 16)
		count += print_hexadecimal(nbr / 16, symbol);
	count += print_char(hex_base[nbr % 16]);
	return (count);
}
