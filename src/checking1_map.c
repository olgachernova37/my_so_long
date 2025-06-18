/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:19:52 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/18 15:06:30 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_extension(char *map)
{
	int	len;

	if (!map)
		return (0);
	len = ft_strlen(map);
	if (len < 4 || ft_strncmp(&map[len - 4], ".ber", 4) != 0)
	{
		ft_printf("Invalid file type, use .ber!\n");
		return (0);
	}
	return (1);
}

void	checking_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error → Entry should be: ./so_long mapXYZ.ber.\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (file_extension(argv[1]) == 0)
	{
		exit(1);
	}
	else if (fd < 0)
	{
		ft_printf("Error → Invalid map file.\n");
		exit(1);
	}
	close(fd);
}

int	count_newlines_in_buffer(char *buffer, ssize_t size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	count_map_rows(char *filename)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		fd;
	int		count;
	int		has_content;

	fd = 0;
	count = 0;
	has_content = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		has_content = 1;
		count += count_newlines_in_buffer(buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (has_content && bytes_read == 0 && (count == 0))
		count++;
	if (buffer[bytes_read - 1] != '\n')
		count++;
	close(fd);
	return (count);
}

char	*append_next_char(int fd, char *line, int *bytes_read)
{
	char	buffer[2];
	char	*temp;

	*bytes_read = read(fd, buffer, 1);
	if (*bytes_read > 0)
	{
		buffer[1] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	return (line);
}
