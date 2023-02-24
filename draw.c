/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:25:30 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 03:40:29 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(char *str, t_mlx *emlx)
{
	printf("here");
	if (ft_strncmp(str, "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		emlx->id = 1;
		ft_mandelbrot(emlx);
	}
	else if(ft_strncmp(str, "burningship", ft_strlen("burningship")) == 0)
	{
		emlx->id = 2;
		ft_burningship(emlx);
	}

	mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	mlx_hook(emlx->win, 2, 0, key_press, (void *)emlx);
	mlx_hook(emlx->win, 17, 0, close, (void *)emlx);
	mlx_hook(emlx->win, 4, 0, mouse_press, (void *)emlx);
	mlx_loop(emlx->mlx);
	
}