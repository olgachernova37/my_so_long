/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:39:20 by olcherno          #+#    #+#             */
/*   Updated: 2025/01/08 15:50:00 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			readcheck;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	readcheck = reading(fd, &buffer);
	if (readcheck < 0 || !buffer || (*buffer == '\0' && readcheck == 0))
		return (free(buffer), buffer = NULL, NULL);
	line = cutting(&buffer);
	return (line);
}

int	reading(int fd, char **buffer)
{
	int		readcheck;
	char	*new;

	readcheck = 1;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (-1);
	while (readcheck > 0)
	{
		readcheck = read(fd, new, BUFFER_SIZE);
		if (readcheck < 0)
		{
			free(new);
			return (-1);
		}
		new[readcheck] = '\0';
		*buffer = free_storeg(*buffer, new);
		if (!*buffer)
			return (free(new), -1);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	free(new);
	return (readcheck);
}

char	*free_storeg(char *buffer, const char *s2)
{
	char	*res;
	int		lenbuffer;
	int		lens2;

	lenbuffer = ft_strlen(buffer);
	lens2 = ft_strlen(s2);
	res = malloc(lenbuffer + lens2 + 1);
	if (!res)
		return (free(buffer), buffer = NULL, NULL);
	ft_memcpy(res, buffer, lenbuffer);
	ft_memcpy(res + lenbuffer, s2, lens2);
	res[lenbuffer + lens2] = '\0';
	free(buffer);
	return (res);
}

char	*cutting(char **buffer)
{
	char	*line;
	char	*left;
	int		i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = allocates_copy(*buffer, i);
	left = allocates_copy(*buffer + i, ft_strlen(*buffer + i));
	free(*buffer);
	if (!line || !left)
		return (free(line), free(left), *buffer = NULL, NULL);
	*buffer = left;
	return (line);
}

char	*allocates_copy(const char *src, int lenbuffer)
{
	char	*dest;

	if (lenbuffer == 0)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(lenbuffer + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, lenbuffer);
	dest[lenbuffer] = '\0';
	return (dest);
}
