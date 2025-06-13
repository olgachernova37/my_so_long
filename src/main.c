/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:27:23 by olcherno          #+#    #+#             */
/*   Updated: 2025/06/13 20:23:03 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_map(char **map)
{
    int i;
    int j;

    if (!map)
        return;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            ft_printf("%c", map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}

int	main(int argc, char **argv)
{
    t_map	game;

    checking_input(argc, argv);
    game.map = read_map(argv[1]);
    if (!game.map)
    {
        ft_printf("Error → Failed to read map.\n");
        exit(1);
    }
    print_map(game.map);

    check_map(&game);
    
    // Process the map here
    free_map(game.map);
    return (0);
}

// #define MALLOC_ERROR	1
// #define	SIDE_LEN		800
// #define X				50
// #define Y				50

// typedef struct s_img
// {

// 	void	*img_ptr;
// 	char	*img_pixels_ptr;
// 	int		bits_per_pixel;
// 	int		endian;
// 	int		line_len;
// }				t_img;

// /*
//  * This struct contains all the mlx stuff
//  * and the image where i will buffer my pixels
// */
// typedef struct	s_var
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// }				t_var;

// void	my_pixel_put(t_img *img, int x, int y, int color)
// {
// 	int	offset;

// 	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
// 	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

// 	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
// }

// /*
//  * 🔥 my_pixel_put
// */
// void	color_screen(t_var *data, int color)
// {
// 			my_pixel_put(&data->img,
// 						X,
// 						Y,
// 						color);
// }

// int	f(int keysym, t_var *data)
// {

// 	if (keysym == XK_r)
// 	{
// 		color_screen(data, 0xff0000);
// 	}
// 	else if (keysym == XK_g)
// 	{
// 		color_screen(data, 0xff00);
// 	}
// 	else if (keysym == XK_b)
// 	{
// 		color_screen(data, 0xff);
// 	}
// 	else if (keysym == XK_Escape)
// 		exit(1);

// 	// push the READY image to window
// 	// the last parameters are the offset image-window
// 	mlx_put_image_to_window(data->mlx,
// 							data->win,
// 							data->img.img_ptr,
// 							0, 0);

// 	return (0);
// }

// /*
//  * All the checks for errors like
//  *
//  * 	~if (vars.mlx == NULL) exit(1);
//  *
//  * are not written to not clog te code!
//  * But u know this stuff is a necessary evil 😂
// */
// int	main(void)
// {
// 	t_var	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx,
// 								SIDE_LEN,
// 								SIDE_LEN,
// 								"My window");

// 	// Code to create an image and get the related DATA
// 	vars.img.img_ptr = mlx_new_image(vars.mlx,
// 									SIDE_LEN,
// 									SIDE_LEN);
// 	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
// 												&vars.img.bits_per_pixel,
// 												&vars.img.line_len,
// 												&vars.img.line_len,
// 												&vars.img.endian);

// 	printf("Line_len %d <-> SIDE_LEN %d\n"
// 			"bpp %d\n"
// 			"endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel,
// vars.img.endian);

// 	mlx_key_hook(vars.win,
// 				f,
// 				&vars);
// 	mlx_loop(vars.mlx);
// }