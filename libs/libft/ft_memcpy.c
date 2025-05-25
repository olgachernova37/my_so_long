/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:49:27 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/02 17:52:05 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*u_dest;
	const unsigned char	*u_src;

	if (n == 0)
		return (dest);
	if (!dest || !src)
		return (NULL);
	u_dest = (unsigned char *)dest;
	u_src = (const unsigned char *)src;
	while (n--)
		*u_dest++ = *u_src++;
	return (dest);
}
