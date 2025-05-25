/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:47:49 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 15:32:18 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	if (!s || n == 0)
		return (NULL);
	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
	}
	return (NULL);
}
