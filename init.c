/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:09:44 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 20:15:09 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_mlx *emlx)
{
	emlx->wid = 600;
	emlx->hei = 600;
	emlx->mlx = mlx_init();
	emlx->win = mlx_new_window(emlx->mlx, emlx->wid, emlx->hei, "fract-ol");
	emlx->image.img = mlx_new_image(emlx->mlx, emlx->wid, emlx->hei);
	emlx->image.addr = (int *)mlx_get_data_addr(emlx->image.img,
			&emlx->image.bits_per_pixel, &emlx->image.line_length,
			&emlx->image.endian);
	emlx->imin = -2;
	emlx->imax = 2;
	emlx->rmin = -2;
	emlx->rmax = 2;
	emlx->maxiter = 100;
	emlx->zoom = 1;
	emlx->id = 0;
	emlx->mx = -0.70176;
	emlx->my = -0.3842;
	emlx->ud = 0;
	emlx->lr = 0;
	emlx->customize_color = 0xf4fefe;
	emlx->tag = 0;
	emlx->m = 0;
}
