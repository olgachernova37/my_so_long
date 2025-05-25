/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:25:28 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/06 18:23:22 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	temp_c;
	unsigned char	*temp_s;

	if (!s)
		return (NULL);
	temp_c = (unsigned char)c;
	temp_s = (unsigned char *)s;
	while (n--)
		*temp_s++ = temp_c;
	return (s);
}
