/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:19:52 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/17 23:00:46 by olcherno         ###   ########.fr       */
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

int	count_map_rows(char *filename)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		fd = 0;
	int		count = 0;
	int		has_content = 0;  // Track if we've seen any content
	int		i;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
		
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		has_content = 1;  // We've seen content
		
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	
	// If the file had content but didn't end with a newline, add one more line
	if (has_content && bytes_read == 0 && 
        (count == 0 || buffer[bytes_read-1] != '\n'))
        count++;
        
	close(fd);
	return (count);
}

int	count_map_rows_simple(char *filename)
{
	char	c;
	int		fd;
	int		count;

	fd = 0;
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
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
