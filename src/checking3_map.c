/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking3_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:06:35 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/17 20:46:39 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_map_rectangular(t_map *map_struct)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!map_struct || !map_struct->map || map_struct->size_y == 0)
		return (0);
	map_struct->size_x = ft_strlen(map_struct->map[0]);
	while (i < map_struct->size_y)
	{
		len = 0;
		while (map_struct->map[i][len] && map_struct->map[i][len] != '\n')
			len++;
		if (len != map_struct->size_x)
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_map *game)
{
	if (!game || !game->map)
	{
		free_map(game->map);
		ft_msgerror(1);
	}
	game->size_y = 0;
	while (game->map[game->size_y])
		game->size_y++;
	if (game->size_y == 0 || !is_map_rectangular(game))
	{
		free_map(game->map);
		ft_msgerror(1);
	}
	ft_printf("Map size: %d rows\n", game->size_y);
	game->size_x = ft_strlen(game->map[0]);
	if (game->size_x == 0)
	{
		free_map(game->map);
		ft_msgerror(1);
	}
	ft_check_content_map(game);
	validate_map_walls(game->size_x, game->size_y, game);
	ft_fl_fill(game);
}
