/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:32:40 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 00:51:29 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_bonus(char *str, t_mlx *emlx)
{
	if (ft_strcmp(str, "mandelbrot_bonus") == 0)
	{
		emlx->id = 1;
		ft_mandelbrot(emlx);
	}
	else if (ft_strcmp(str, "burningship_bonus") == 0)
	{
		emlx->id = 2;
		ft_burningship(emlx);
	}
	else if (ft_strcmp(str, "julia_bonus") == 0)
	{
		emlx->id = 4;
		ft_julia_bonus(emlx);
	}
	mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	mlx_hook(emlx->win, 2, 0, key_press, (void *)emlx);
	mlx_hook(emlx->win, 17, 0, close, (void *)emlx);
	mlx_hook(emlx->win, 4, 0, mouse_press, (void *)emlx);
	mlx_hook(emlx->win, 6, 0, mouse_move, (void *)emlx);
	mlx_loop(emlx->mlx);
}