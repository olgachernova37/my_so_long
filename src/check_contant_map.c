/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contant_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:05:49 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 20:21:15 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	ft_check_content_map(char **map, t_map *game)
// {
//     int	x;
//     int	y;

//     x = 0;
//     y = 0;
//     while (map[y])
//     {
//         while (map[y][x])
//         {
//             ft_content_condition(map, game, x, y);
//             x++;
//         }
//         if (x != game->size_x)
//             ft_msgerror(1);
//         x = 0;
//         y++;
//     }
//     if (y != game->size_y)
//         ft_msgerror(1);
// }
// void	ft_content_condition(char **map, t_map *game, int x, int y)
// {
//     if (map[y][x] == 'C')
//     {
//         game->coin++;
//     }
//     else if (map[y][x] == 'E')
//     {
//         game->map_e++;
//         game->exit[0] = x;
//         game->exit[1] = y;
//     }
//     else if (map[y][x] == 'P')
//     {
//         game->map_p++;
//         game->start[0] = x;
//         game->start[1] = y;
//     }
//     else if (map[y][x] != '0' && map[y][x] != '1')
//     {
//         ft_msgerror(2);
//     }
// }
// int	ft_check_if_exit(t_map *game)
// {
//     if (game->map_e != 1 || game->map_p != 1 || game->coin < 1)
//     {
//         ft_msgerror(3);
//         return (0);
//     }
//     return (1);
// }
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
        ft_printf("Error → Map must have exactly one exit, one player, and at least one coin.\n");
    else
        ft_printf("Error → Unknown error.\n");
    exit(1);            
}
