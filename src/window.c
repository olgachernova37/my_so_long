/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:26:02 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/18 15:08:38 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_images(t_map *game)
{
	int	width;
	int	height;

	width = game->point;
	height = game->point;
	game->img[0] = mlx_xpm_file_to_image(game->mlx, "src/img/0.xpm", &width,
			&height);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "src/img/1.xpm", &width,
			&height);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "src/img/c.xpm", &width,
			&height);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "src/img/p.xpm", &width,
			&height);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, "src/img/e.xpm", &width,
			&height);
	if (!game->img[0] || !game->img[1] || !game->img[2] || !game->img[3]
		|| !game->img[4])
	{
		ft_printf("Error → Failed to load one or more images.\n");
		exit(1);
	}
}

void	destroy_images(t_map *map)
{
	if (map->img[1])
		mlx_destroy_image(map->mlx, map->img[1]);
	if (map->img[0])
		mlx_destroy_image(map->mlx, map->img[0]);
	if (map->img[3])
		mlx_destroy_image(map->mlx, map->img[3]);
	if (map->img[4])
		mlx_destroy_image(map->mlx, map->img[4]);
	if (map->img[2])
		mlx_destroy_image(map->mlx, map->img[2]);
}

void	free_and_exit(t_map *map)
{
	destroy_images(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free_map(map->map);
	exit(1);
}

int	close_button(t_map *map)
{
	ft_printf("You closed the window. Bye!\n");
	free_and_exit(map);
	return (0);
}

void	ft_init_window(t_map *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error → Failed to initialize MLX.\n");
		free_map(game->map);
		exit(1);
	}
	ft_load_images(game);
	game->mlx_win = mlx_new_window(game->mlx, game->size_x * game->point,
			game->size_y * game->point, "So Long");
	if (!game->mlx_win)
	{
		ft_printf("Error → Failed to create window.\n");
		exit(1);
	}
	draw_map(game);
	game->step = 0;
	display_move_counter(game);
	mlx_key_hook(game->mlx_win, key_move, game);
	mlx_hook(game->mlx_win, 17, 0, close_button, game);
	mlx_loop(game->mlx);
}
