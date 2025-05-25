/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:48:04 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/06 16:48:34 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_counter(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
	{
		n = -n;
		counter++;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	ft_convert_to_string(int n, char **temp, int *big_10)
{
	while (*big_10 > n)
		*big_10 /= 10;
	while (*big_10 >= 10)
	{
		**temp = n / *big_10 + '0';
		*temp += 1;
		n = n - (n / *big_10) * *big_10;
		*big_10 /= 10;
	}
	**temp = n + '0';
	*temp += 1;
}

char	*ft_itoa(int n)
{
	int		big_10;
	char	*temp;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (ft_number_counter(n) + 1));
	if (!result)
		return (NULL);
	temp = result;
	if (n < 0)
	{
		n = -n;
		*temp++ = '-';
	}
	big_10 = 1000000000;
	ft_convert_to_string(n, &temp, &big_10);
	*temp = '\0';
	return (result);
}
