/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:34:26 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 23:22:33 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clearwindow(t_mlx *emlx)
{
	int	i;
	int	j;

	j = emlx->wid * emlx->hei;
	i = 0;
	while (emlx->image.addr[i] < j)
	{
		emlx->image.addr[i] = 0x000000;
		i++;
	}	
}

int	key_press(int keycode, t_mlx *emlx)
{
	if (keycode == 53 && emlx)
		exit(0);
	else if (keycode == 69 && emlx)
	{
		emlx->maxiter += 10;
	}	
	else if (keycode == 78 && emlx)
	{
		emlx->maxiter -= 10;
	}
	else if ((keycode == 123 || keycode == 124
			|| keycode == 125 || keycode == 126) && emlx && emlx->tag == 1)
		move_shape(emlx, keycode);
	else if (keycode == 18 && emlx && emlx->tag == 1)
		cust_color_button(emlx, keycode);
	ft_clearwindow(emlx);
	if (emlx->id == 3)
		ft_mandelbrot_bonus(emlx);
	else if (emlx->id == 4)
		ft_burningship(emlx);
	else if (emlx->id == 5)
		ft_julia_bonus(emlx);
	mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	return (0);
}

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_mlx	*emlx;

	emlx = (t_mlx *)param;
	emlx->mx = x;
	emlx->my = y;
	if (emlx->id == 5)
	{
		ft_clearwindow(emlx);
		ft_julia_bonus(emlx);
		mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*emlx;

	emlx = (t_mlx *)param;
	if ((button == 4 || button == 5) && emlx)
	{
		ft_zoom(emlx, button, x, y);
	}
	ft_clearwindow(emlx);
	if (emlx->id == 1)
		ft_mandelbrot(emlx);
	else if (emlx->id == 2)
		ft_julia(emlx);
	else if (emlx->id == 3)
		ft_mandelbrot_bonus(emlx);
	else if (emlx->id == 4)
		ft_burningship(emlx);
	else if (emlx->id == 5)
		ft_julia_bonus(emlx);
	mlx_put_image_to_window(emlx->mlx, emlx->win, emlx->image.img, 0, 0);
	return (0);
}
