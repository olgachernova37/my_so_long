/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:58 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/25 12:56:15 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_str("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_nbr(int num)
{
	long	nlong;
	int		count;
	char	c;

	count = 0;
	nlong = num;
	if (nlong < 0)
	{
		count += write(1, "-", 1);
		nlong = -nlong;
	}
	if (nlong >= 10)
	{
		count += print_nbr(nlong / 10);
	}
	c = nlong % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	unsigned_print_nbr(unsigned int num)
{
	int		count;
	char	c;

	count = 0;
	if (num >= 10)
	{
		count += unsigned_print_nbr(num / 10);
	}
	c = num % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}
