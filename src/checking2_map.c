/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:21:12 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 19:33:02 by olcherno         ###   ########.fr       */
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

int fill_map_from_file(char **map, int rows, char *filename)
{
    char    *line;
    int     fd;
    int     i;

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
        if (!line) {
			
            break;
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
		return (NULL);
	return (map);
}
