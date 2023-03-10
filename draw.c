/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:25:30 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 20:38:36 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(char *str, t_mlx *emlx)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		emlx->id = 1;
		ft_mandelbrot(emlx);
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		emlx->id = 2;
		ft_julia(emlx);
	}
	mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	mlx_hook(emlx->win, 2, 0, key_press, (void *)emlx);
	mlx_hook(emlx->win, 17, 0, ft_close, (void *)emlx);
	mlx_hook(emlx->win, 4, 0, mouse_press, (void *)emlx);
	mlx_loop(emlx->mlx);
}
