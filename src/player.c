/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:27:23 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/18 15:08:47 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_map *map, int new_x, int new_y)
{
	char	next_tile;

	next_tile = map->map[new_y][new_x];
	if (next_tile == '1' || (next_tile == 'E' && map->coin != 0))
		return ;
	if (next_tile == 'C')
		map->coin--;
	if (next_tile == 'E' && map->coin == 0)
	{
		ft_printf("You won!\n");
		free_and_exit(map);
		return ;
	}
	map->map[map->start[1]][map->start[0]] = '0';
	map->start[0] = new_x;
	map->start[1] = new_y;
	map->map[new_y][new_x] = 'P';
	map->step++;
	ft_printf("Moves: %d\n", map->step);
	draw_map(map);
	display_move_counter(map);
}

void	display_move_counter(t_map *map)
{
	char	*count_str;
	char	*full_str;

	count_str = ft_itoa(map->step);
	full_str = ft_strjoin("Moves: ", count_str);
	mlx_string_put(map->mlx, map->mlx_win, 10, map->size_y * map->point - 20,
		0xFFFFFF, full_str);
	mlx_string_put(map->mlx, map->mlx_win, 10, map->size_y * map->point - 20,
		0xFFFFFF, full_str);
	mlx_string_put(map->mlx, map->mlx_win, 11, map->size_y * map->point - 20,
		0xFFFFFF, full_str);
	free(count_str);
	free(full_str);
}

void	put_tile(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * map->point, y
		* map->point);
}

void	draw_map(t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == '1')
				put_tile(map, x, y, map->img[1]);
			else if (map->map[y][x] == '0')
				put_tile(map, x, y, map->img[0]);
			else if (map->map[y][x] == 'P')
				put_tile(map, x, y, map->img[3]);
			else if (map->map[y][x] == 'E')
				put_tile(map, x, y, map->img[4]);
			else if (map->map[y][x] == 'C')
				put_tile(map, x, y, map->img[2]);
			x++;
		}
		y++;
	}
}

int	key_move(int key, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->start[0];
	new_y = map->start[1];
	if (key == 119 || key == 65362)
		new_y--;
	else if (key == 115 || key == 65364)
		new_y++;
	else if (key == 97 || key == 65361)
		new_x--;
	else if (key == 100 || key == 65363)
		new_x++;
	else if (key == 65307)
	{
		free_and_exit(map);
		return (0);
	}
	move_player(map, new_x, new_y);
	return (0);
}
