/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:19:45 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/18 15:36:31 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/libftprintf/ft_printf.h"
# include "libs/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"
# define ESC 65307
# define W 119
# define A 97
# define D 100
# define S 115

typedef struct s_map
{
	char	**map;
	size_t	size_x;
	size_t	size_y;
	int		coin;
	int		map_e;
	int		map_p;
	int		start[2];
	int		exit[2];
	void	*mlx;
	void	*mlx_win;
	void	*img[6];
	int		step;
	int		needcoin;
	int		nbrimg;
	int		point;
}			t_map;

int			file_extension(char *map);
void		checking_input(int argc, char **argv);
int			count_map_rows(char *filename);
int			count_map_rows_simple(char *filename);
char		*read_map_line(int fd);
char		**allocate_map(int rows);
void		free_partial_map(char **map, int filled);
int			fill_map_from_file(char **map, int rows, char *filename);
char		**read_map(char *filename);
void		free_map(char **map);
char		*get_next_line_so_long(int fd);
char		*append_next_char(int fd, char *line, int *bytes_read);

void		check_map(t_map *game);
int			is_map_rectangular(t_map *map_struct);
void		ft_msgerror(int error);

void		ft_check_content_map(t_map *map);
void		ft_content_condition(t_map *map, int x, int y);
int			ft_check_c_p_e(t_map *map);
void		validate_map_walls(int width, int height, t_map *map);

void		ft_fl_fill(t_map *map);
void		passability(t_map *map, size_t x, size_t y);
void		passabilityrefill(t_map *map, size_t x, size_t y);
void		ft_free_exit(t_map *map);
void		ft_init_window(t_map *game);
void		ft_load_images(t_map *game);
void		put_tile(t_map *map, int x, int y, void *img);
void		draw_map(t_map *map);
int			key_move(int key, t_map *map);
void		move_player(t_map *map, int new_x, int new_y);
void		display_move_counter(t_map *map);
void		free_and_exit(t_map *map);
int			count_newlines_in_buffer(char *buffer, ssize_t size);
void		destroy_images(t_map *map);
int			close_button(t_map *map);

#endif
