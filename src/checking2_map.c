/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:21:12 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/17 20:46:28 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**allocate_map(int rows)
{
	char	**map;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		ft_printf("Failed to allocate memory for map\n");
	return (map);
}

int	fill_map_from_file(char **map, int rows, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to open file: %s\n", filename);
		return (0);
	}
	while (i < rows)
	{
		line = read_map_line(fd);
		if (!line)
		{
			break ;
		}
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	ft_printf("Successfully read %d lines\n", i);
	return (1);
}

char	**read_map(char *filename)
{
	int		rows;
	char	**map;

	rows = count_map_rows(filename);
	if (rows <= 0)
		return (NULL);
	map = allocate_map(rows);
	if (!map)
		return (NULL);
	if (!fill_map_from_file(map, rows, filename))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

char	*get_next_line_so_long(int fd)
{
	char	*line;
	int		bytes_read;

	bytes_read = 1;
	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (bytes_read > 0)
	{
		line = append_next_char(fd, line, &bytes_read);
		if (!line)
			return (NULL);
		if (bytes_read > 0 && line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	if (bytes_read <= 0 && (!line || !*line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*read_map_line(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line_so_long(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
