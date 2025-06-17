/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:58:27 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/17 22:09:26 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	passability(t_map *map, size_t x, size_t y)
{
	if (x >= map->size_x || y >= map->size_y)
		return ;
	if (map->map[y][x] == '1' || map->map[y][x] == 'o' || map->map[y][x] == 'c'
		|| map->map[y][x] == 'e')
		return ;
	if (map->map[y][x] == '0')
		map->map[y][x] = 'o';
	else if (map->map[y][x] == 'C')
		map->map[y][x] = 'c';
	else if (map->map[y][x] == 'E')
	{
		map->map[y][x] = 'e';
		return ;
	}
	passability(map, x + 1, y);
	passability(map, x - 1, y);
	passability(map, x, y + 1);
	passability(map, x, y - 1);
}

void	passabilityrefill(t_map *map, size_t x, size_t y)
{
	if (x >= map->size_x || y >= map->size_y)
		return ;
	if (map->map[y][x] == '1' || map->map[y][x] == '0' || map->map[y][x] == 'C'
		|| map->map[y][x] == 'E')
		return ;
	if (map->map[y][x] == 'o')
		map->map[y][x] = '0';
	else if (map->map[y][x] == 'c')
		map->map[y][x] = 'C';
	else if (map->map[y][x] == 'e')
	{
		map->map[y][x] = 'E';
		return ;
	}
	passabilityrefill(map, x + 1, y);
	passabilityrefill(map, x - 1, y);
	passabilityrefill(map, x, y + 1);
	passabilityrefill(map, x, y - 1);
}

void	ft_fl_fill(t_map *map)
{
	size_t	y;
	size_t	x;

	passability(map, map->start[0], map->start[1]);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == 'E' || map->map[y][x] == 'C')
			{
				ft_printf("Error\nExit or collectible unreachable\n");
				ft_free_exit(map);
			}
			++x;
		}
		++y;
	}
	passabilityrefill(map, map->start[0], map->start[1]);
}

void	ft_free_exit(t_map *map)
{
	if (map)
	{
		if (map->map)
			free_map(map->map);
		ft_bzero(map, sizeof(t_map));
	}
	exit(1);
}
