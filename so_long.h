/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:19:45 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 20:21:23 by olcherno         ###   ########.fr       */
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
}			t_map;

typedef struct s_startmlx
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img[6];
	size_t	size_x;
	size_t	size_y;
	int		step;
	int		coin;
	int		needcoin;
	int		nbrimg;
	int		start[2];
	int		exit[2];
}			t_startmlx;

// int		ft_msgerror(int error);
// char	*ft_read_file(char *map);
// void	ft_freemap(char **map);
// char	**check_map(char *map, t_map *game);
// void	ft_check_content_map(char **map, t_map *game);
// void	ft_content_condition(char **map, t_map *game, int x, int y);
// int		ft_pathfind(t_map *game, int pox, int poy, int *count);
// void	ft_pathvalid(t_map *game, char *mapname, t_startmlx *gplay);
// void	ft_beforepathfind(t_map *game, int pox, int poy, int *count);
// int		ft_check_if_exit(t_map *game);
// void	ft_finalmap(t_map *game, char *mapname, t_startmlx *gplay);
// void	ft_fillmap(t_startmlx *gplay);
// int		deal_key(int keysym, t_startmlx *gplay);
// void	ft_empty_struct(t_startmlx *gplay, t_map *game);
// void	ft_empty_t_map(t_map *game);
// void	ft_exit(t_startmlx *gplay, t_map *game);
// void	ft_put_image(t_startmlx *gplay, int i_img, int x, int y);
// int		close_x(t_startmlx *gplay);

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
void ft_msgerror(int error);


#endif