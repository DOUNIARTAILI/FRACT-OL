/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:33:22 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 20:34:23 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_mlx *emlx)
{
	emlx->y = 0;
	while (emlx->y < (int)emlx->hei)
	{
		emlx->x = 0;
		while (emlx->x < (int)emlx->wid)
		{
			emlx->iter = 1;
			emlx->c.r = emlx->rmin + (emlx->x + emlx->lr)
				/ (double)emlx->wid * (emlx->rmax - emlx->rmin);
			emlx->c.i = emlx->imin + (emlx->y + emlx->ud)
				/ (double)emlx->hei * (emlx->imax - emlx->imin);
			emlx->z.r = 0.0;
			emlx->z.i = 0.0;
			emlx->new_z = emlx->z;
			escaped_or_not(emlx);
			color_it(emlx);
			emlx->image.addr[emlx->y * (int)emlx->wid + emlx->x] = emlx->color;
			emlx->x++;
		}
		emlx->y++;
	}
}
