/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:43:12 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 15:32:13 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last;
	unsigned char	uc;

	if (!s)
		return (NULL);
	last = NULL;
	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == (char)uc)
			last = (char *)&s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (last);
}
