/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:21:12 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 18:28:09 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Allocates the map array based on the number of rows
char	**allocate_map(int rows)
{
	char	**map;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		ft_printf("Failed to allocate memory for map\n");
	return (map);
}

// Helper to free partially filled map
// void	free_partial_map(char **map, int filled)
// {
// 	int	j;

// 	j = 0;
// 	while (j < filled)
// 	{
// 		free(map[j]);
// 		j++;
// 	}
// 	free(map);
// }

// Reads the whole map file into a NULL-terminated array of strings
// Opens the map file and fills the map array with lines, returns 1 on success,
// 0 on error
// int	fill_map_from_file(char **map, int rows, char *filename)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	fd = 0;
// 	i = 0;
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_printf("Failed to open file: %s\n", filename);
// 		return (0);
// 	}
// 	line = read_map_line(fd);
// 	while (i < rows && (line))
// 		map[i++] = line;
// 	if (i < rows)
// 	{
// 		free_map(map);
// 		// free(line);
// 		close(fd);
// 		return (0);
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	ft_printf("Successfully read %d lines\n", i);
// 	return (1);
// }

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
    
    // Read a NEW line for EACH position in the array
    while (i < rows)
    {
        line = read_map_line(fd);
        if (!line) {
			
            break;
		}
        map[i++] = line;
    }
    // free(line);
    if (i < rows)
    {
        free_map(map);
        close(fd);
		free(line);
        return (0);
    }
    free(line);
    map[i] = NULL;
    close(fd);
    ft_printf("Successfully read %d lines\n", i);
    return (1);
}

// Allocates and reads the map file into a NULL-terminated array of strings
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

void free_map(char **map)
{
    int i = 0;
    
    if (!map)
        return;
    
    while (map[i]) 
	{
        free(map[i]);
        i++;
    }
    free(map);
}
