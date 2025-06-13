/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking3_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:06:35 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 20:40:23 by olcherno         ###   ########.fr       */
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
	size_t i = 0;

	if (!map_struct || !map_struct->map || map_struct->size_y == 0)
		return (0);
    map_struct->size_x= ft_strlen(map_struct->map[0]);
	while (i < map_struct->size_y)
	{

		size_t len = 0;
		while (map_struct->map[i][len] && map_struct->map[i][len] != '\n')
			len++;
		if (len != map_struct->size_x)
			return (0); // not rectangular
		i++;
	}
	return (1); // rectangular
}

void check_map(t_map *game)
{
    if (!game || !game->map)
    {
    ft_msgerror(1);
    return;
    }
    
    game->size_y = 0;
    while (game->map[game->size_y])
        game->size_y++;
    ft_printf("%d\n", is_map_rectangular(game));
    if (game->size_y == 0 || !is_map_rectangular(game))
    {
        ft_msgerror(1);
        return;
    }
    ft_printf("Map size: %d rows\n", game->size_y);
    game->size_x = ft_strlen(game->map[0]);
    if (game->size_x == 0)
    {
    ft_msgerror(1);
    return;
    } 
}
