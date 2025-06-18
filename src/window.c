/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olha <olha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:26:02 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/18 12:32:54 by olha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int ft_key_hook(int key, t_map *game)
// {
//     int keysym;

//     keysym = mlx_key_get_keycode(key);
//     if (keysym == ESC)
//     {
//         mlx_destroy_window(game->mlx, game->mlx_win);
//         exit(0);
//     }

//     // Handle other key events here
//     return (0);
// }

void	ft_load_images(t_map *game)
{
	int	width;
	int	height;

	width = game->point;
	height = game->point;
	game->img[0] = mlx_xpm_file_to_image(game->mlx, "src/img/0.xpm", &width,
			&height);
	if (!game->img[0])
	{
		ft_printf("Error → Failed to load grass image.\n");
		exit(1);
	}
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "src/img/1.xpm", &width,
			&height);
	if (!game->img[1])
	{
		ft_printf("Error → Failed to load wall image.\n");
		exit(1);
	}
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "src/img/c.xpm", &width,
			&height);
	if (!game->img[2])
	{
		ft_printf("Error → Failed to load coin image.\n");
		exit(1);
	}
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "src/img/p.xpm", &width,
			&height);
	if (!game->img[3])
	{
		ft_printf("Error → Failed to load player image.\n");
		exit(1);
	}
	game->img[4] = mlx_xpm_file_to_image(game->mlx, "src/img/e.xpm", &width,
			&height);
	if (!game->img[4])
	{
		ft_printf("Error → Failed to load exit image.\n");
		exit(1);
	}
}
void	put_tile(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * map->point, y * map->point);
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

void	destroy_all(t_map *map)
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
}

void	exit_game(t_map *map)
{
	destroy_all(map);
	exit(EXIT_SUCCESS);
}

// int	ft_key_hook(int key, t_map *game)
// {
// 	if (key == ESC) // Escape key
// 	{
// 		mlx_destroy_window(game->mlx, game->mlx_win);
// 		exit(0);
// 	}
// 	// Handle MOUSE BUTTON CLOSE ON CROSS
// 	if (key == 17) // Assuming 17 is the keycode for the close button
// 	{
// 		mlx_destroy_window(game->mlx, game->mlx_win);
// 		exit(0);
// 	}
// 	if (key == XK_Escape)
// 	{
// 		mlx_destroy_window(game->mlx, game->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

void display_move_counter(t_map *map)
{
	char *count_str;
	char *full_str;

	count_str = ft_itoa(map->step);
	full_str = ft_strjoin("Moves: ", count_str);

	// Display with better positioning and white color
	mlx_string_put(map->mlx, map->mlx_win, 10, map->size_y * map->point - 20, 0xFF0000, full_str);
	mlx_string_put(map->mlx, map->mlx_win, 10, map->size_y * map->point - 20, 0xFFFFFF, full_str);
	mlx_string_put(map->mlx, map->mlx_win, 11, map->size_y * map->point - 19, 0xFFFFFF, full_str);

	free(count_str);
	free(full_str);
}

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
		exit_game(map);
		return ;
	}
	
	// Clear old position - fixed to use y,x indexing consistently
	map->map[map->start[1]][map->start[0]] = '0';
	
	// Update player position in your tracking array
	map->start[0] = new_x;
	map->start[1] = new_y;
	
	// Set new position in map
	map->map[new_y][new_x] = 'P';
	
	map->step++;
	ft_printf("Moves: %d\n", map->step);
	draw_map(map);              // First draw the map
    display_move_counter(map);  // Then draw the text ON TOP of the map
}

int	on_keypress(int key, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->start[0];
	new_y = map->start[1];
	if (key == 119 || key == 65362)
		new_y--;
	else if (key == 115 || key== 65364)
		new_y++;
	else if (key == 97 || key == 65361)
		new_x--;
	else if (key == 100 || key == 65363)
		new_x++;
	else if (key == 65307)
	{
		exit_game(map);
		return (0);
	}
	move_player(map, new_x, new_y);
	return (0);
}


int	on_destroy(t_map *map)
{
	ft_printf("You closed the window. Bye!\n");
	exit_game(map);
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
	game->mlx_win = mlx_new_window(game->mlx, game->size_x * game->point, game->size_y
			* game->point, "So Long");
	if (!game->mlx_win)
	{
		ft_printf("Error → Failed to create window.\n");
		exit(1);
	}

	draw_map(game);
	// usleep(1000000);
	game->step = 0;
	display_move_counter(game);
	mlx_key_hook(game->mlx_win, on_keypress, game);
    mlx_hook(game->mlx_win, 17, 0, on_destroy, game); // Close window on cross button
	mlx_loop(game->mlx);
}
