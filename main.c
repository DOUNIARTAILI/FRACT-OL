/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:43:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 01:19:10 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// #include "mlx.h"
// #include <stdlib.h>
// #include <math.h>
// #include <stdio.h>

// typedef struct s_point{
// 	double r;
// 	double i;
// }t_point;

// typedef struct	s_data {
// 	void	*img;
// 	int		*addr;
// 	int		bits_per_pixel;
// 	int		line_length; 
// 	int		endian;
// }				t_data;

// typedef	struct s_mlx
// {
// 	t_point	c;
// 	t_point	z;
// 	t_data	image;
// 	t_point	new_z;
// 	int x;
// 	int color;
// 	int y;
// 	int iter;
// 	void *mlx;
// 	void *win;
// }t_mlx;

// double	puissance_2(double n)
// {
// 	return (n * n);
// }

// double	calcul_c(double	zr, double zi)
// {
// 	return (puissance_2(zr) + puissance_2(zi));
// }



int main(int argc, char **argv)
{
	t_mlx	*emlx;
	// int p;
	printf("here");
	if (argc <= 1 || argc > 2)
		exit(0);
	printf("test");
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ft_setup(argv[1], emlx) == 0)
	exit (0);
	ft_init(emlx);
	// emlx = (t_mlx *)malloc(sizeof(t_mlx));
	// emlx->mlx = mlx_init();
	// emlx->win = mlx_new_window(emlx->mlx, 800, 800, "mandelbrot");
	// emlx->image.img = mlx_new_image(emlx->mlx, 800, 800);
	// emlx->image.addr = (int*)mlx_get_data_addr(emlx->image.img, &emlx->image.bits_per_pixel, &emlx->image.line_length, &emlx->image.endian);
	draw(argv[1], emlx);
	// emlx->y = 0;
	// while(emlx.y < 800)
	// {
	// 	emlx.x = 0;
	// 	while (emlx.x < 800)
	// 	{
	// 		emlx.iter = 1;
	// 		emlx.c.r = -2 + emlx.x / 800.00 * 4; //maping
	// 		emlx.c.i = -2 + emlx.y / 800.00 * 4;
	// 		emlx.z.r = 0.0;
	// 		emlx.z.i = 0.0;
	// 		emlx.new_z = emlx.z;
	// 		while (calcul_c(emlx.z.r, emlx.z.i) < 4 && emlx.iter < 100)
	// 		{
	// 			emlx.new_z.r = (puissance_2(emlx.z.r) - puissance_2(emlx.z.i)) + emlx.c.r;
	// 			emlx.new_z.i = (2 * emlx.z.r * emlx.z.i) + emlx.c.i;
	// 			emlx.z = emlx.new_z;
	// 			emlx.iter++;
	// 		}
	// 		if (emlx.iter == 100)
	// 			emlx.color = 0;
	// 		else
	// 			emlx.color = 0xf4fefe * emlx.iter; //blue 
	// 		// mlx_pixel_put(mlx, win, x, y, color);
	// 		emlx.image.addr[emlx.y * 800 + emlx.x] = emlx.color;
	// 		emlx.x++;
	// 	}
	// 	emlx.y++;
	// }
	// mlx_put_image_to_window(emlx.mlx, emlx.win, emlx.image.img, 0, 0);
	// mlx_hook(emlx.win, 2, 0, key_press, (void *)&emlx);
	// mlx_hook(emlx.win, 17, 0, close, (void *)&emlx);
	// mlx_hook(emlx.win, 4, 0, mouse_press, (void *)&p);
	// mlx_loop(emlx.mlx);
	return (0);
}