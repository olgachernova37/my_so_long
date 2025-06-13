/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:19:52 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 18:29:53 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int file_extension(char *map)
{
    int len;
    
    if (!map)
        return (0);
    
    len = ft_strlen(map);
    if (len < 4 || ft_strncmp(&map[len-4], ".ber", 4) != 0)
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
		ft_printf("Error → Invalid map extension.\n");
		exit(1);
	}
	else if (fd < 0)
	{
		ft_printf("Error → Invalid map file.\n");
		exit(1);
	}
	close(fd);
}

int	count_map_rows(char *filename)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	int fd = 0;
    int count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		for (int i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
				count++;
		}
	}
	close(fd);
	return (count);
}

int	count_map_rows_simple(char *filename)
{
	char	c;

	int fd, count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	// Count one char at a time - slower but more reliable
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

// Reads a single line from fd, trims the newline,
// returns malloc'd string or NULL on error/EOF

char	*read_map_line(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
