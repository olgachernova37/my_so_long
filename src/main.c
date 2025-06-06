#include "../so_long.h"

static int	file_extension(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'r' && map[i - 1] == 'e'
		&& map[i - 2] == 'b' && map[i - 3] == '.')
		return (1);
	return (0);
}

void checking_input (int argc, char** argv)
{
	int fd;

	if (argc != 2)
	{
		ft_printf("Error → Entry should be: ./so_long mapXYZ.ber.\n");
		exit (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (map_checker(argv[1]) == 0)
	{
		ft_printf("Error → Invalid map extension.\n");
		exit (1);
	}
	else if (fd < 0)
	{
		ft_printf("Error → Invalid map file.\n");
		exit (1);
	}
	return (1);
}

int main(int argc, char** argv) 
{
	checking_input (argc, argv);


	return(0);
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

// 	return 0;
// }


// /*
//  * All the checks for errors like
//  *
//  * 	~if (vars.mlx == NULL) exit(1);
//  *
//  * are not written to not clog te code!
//  * But u know this stuff is a necessary evil 😂
// */
// int	main()
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
// 												&vars.img.endian);


// 	printf("Line_len %d <-> SIDE_LEN %d\n"
// 			"bpp %d\n"
// 			"endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);

// 	mlx_key_hook(vars.win,
// 				f,
// 				&vars);
// 	mlx_loop(vars.mlx);
// }
