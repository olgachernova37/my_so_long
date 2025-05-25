/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:05 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/25 16:04:49 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size ++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_add(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = size_hex_address(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (print_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_add(n / 16);
		ft_hex_add(n % 16);
	}
	return (size);
}

int	print_address(void *ptr)
{
	int	n;

	if (ptr == NULL)
	{
		print_str("(nil)");
		return (5);
	}
	if (print_str("0x") == -1)
		return (-1);
	n = ft_hex_add((unsigned long long)ptr);
	if (n != 0)
		return (n + 2);
	else
		return (0);
}

int	print_specifier(char symbol, va_list args)
{
	int	counter;

	counter = 0;
	if (symbol == 'c')
		counter += print_char(va_arg(args, int));
	else if (symbol == 's')
		counter += print_str(va_arg(args, char *));
	else if (symbol == 'i' || symbol == 'd')
		counter += print_nbr(va_arg(args, int));
	else if (symbol == 'u')
		counter += unsigned_print_nbr(va_arg(args, unsigned int));
	else if (symbol == 'p')
		counter += print_address(va_arg(args, void *));
	else if (symbol == 'x' || symbol == 'X')
		counter += print_hexadecimal(va_arg(args, unsigned long), symbol);
	else
		counter += write(1, &symbol, 1);
	return (counter);
}
