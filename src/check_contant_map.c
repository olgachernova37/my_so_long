/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contant_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:05:49 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/17 22:51:21 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_content_map(t_map *map)
{
	size_t	x;
	size_t	y;

	map->coin = 0;
	map->map_e = 0;
	map->map_p = 0;
	map->needcoin = 0;
	map->step = 0;
	x = 0;
	y = 0;
	while (map->map[y])
	{
		while (map->map[y][x])
		{
			ft_content_condition(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	if (!(ft_check_c_p_e(map)))
	{
		free_map(map->map);
		ft_msgerror(3);
	}
}

void	ft_content_condition(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
	{
		map->coin++;
	}
	else if (map->map[y][x] == 'E')
	{
		map->map_e++;
		map->exit[0] = x;
		map->exit[1] = y;
	}
	else if (map->map[y][x] == 'P')
	{
		map->map_p++;
		map->start[0] = x;
		map->start[1] = y;
	}
	else if (map->map[y][x] != '0' && map->map[y][x] != '1')
	{
		free_map(map->map);
		ft_msgerror(2);
	}
}

int	ft_check_c_p_e(t_map *map)
{
	if (map->map_e != 1 || map->map_p != 1 || map->coin < 1)
	{
		free_map(map->map);
		ft_msgerror(3);
		return (0);
	}
	return (1);
}

void	validate_map_walls(int width, int height, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < width - 1)
	{
		if (map->map[0][x] != '1' || map->map[height - 1][x] != '1')
		{
			free_map(map->map);
			ft_msgerror(5);
		}
		x++;
	}
	y = 0;
	while (y < height - 1)
	{
		if (map->map[y][0] != '1' || map->map[y][width - 1] != '1')
		{
			free_map(map->map);
			ft_msgerror(5);
		}
		y++;
	}
}

// void	ft_finalmap(t_map *game, char *mapname, t_startmlx *gplay)
// {
//     if (!ft_check_if_exit(game))
//         exit(1);
//     ft_pathvalid(game, mapname, gplay);
//     ft_fillmap(gplay);
//     ft_empty_struct(gplay, game);
// }

// void	ft_empty_struct(t_startmlx *gplay, t_map *game)
// {
//     gplay->map = NULL;
//     gplay->mlx = NULL;
//     gplay->mlx_win = NULL;
//     gplay->img[0] = NULL;
//     gplay->img[1] = NULL;
//     gplay->img[2] = NULL;
//     gplay->img[3] = NULL;
//     gplay->img[4] = NULL;
//     gplay->img[5] = NULL;
//     gplay->size_x = game->size_x;
//     gplay->size_y = game->size_y;
//     gplay->step = 0;
//     gplay->coin = 0;
//     gplay->needcoin = game->coin;
//     gplay->nbrimg = 0;
// }
// void	ft_empty_t_map(t_map *game)
// {
//     game->map = NULL;
//     game->size_x = 0;
//     game->size_y = 0;
//     game->coin = 0;
//     game->map_e = 0;
//     game->map_p = 0;
//     game->start[0] = -1;
//     game->start[1] = -1;
//     game->exit[0] = -1;
//     game->exit[1] = -1;
// }
void	ft_msgerror(int error)
{
	if (error == 1)
		ft_printf("Error → Invalid map size.\n");
	else if (error == 2)
		ft_printf("Error → Invalid character in map.\n");
	else if (error == 3)
		ft_printf("Error → Map must have exactly one exit, one player,\
			and at least one coin.\n");
	else if (error == 4)
		ft_printf("Error → Map is not rectangular.\n");
	else if (error == 5)
		ft_printf("Error → Map is not closed by walls.\n");
	else if (error == 6)
		ft_printf("Error → Map is not closed by walls.\n");
	else
		ft_printf("Error → Unknown error.\n");
	exit(1);
}
