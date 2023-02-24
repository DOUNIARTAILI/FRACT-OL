/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:42:41 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 18:46:01 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_mlx *emlx)
{
emlx->y = 0;
			printf("x %f, y %f\n", emlx->mx, emlx->my);
	while(emlx->y < (int)emlx->H)
	{
		emlx->x = 0;
		while (emlx->x < (int)emlx->W)
		{
			
			emlx->iter = 1;
			emlx->c.r = emlx->rmin + emlx->mx / (double)emlx->W * (emlx->rmax - emlx->rmin);
			emlx->c.i = emlx->imin + emlx->my / (double)emlx->H * (emlx->imax - emlx->imin);
			
			// emlx->c.r = -0.70176;
			// emlx->c.i = -0.3842;
			// emlx->c.r = emlx->rmin + (emlx->x + emlx->lr) / (double)emlx->W * (emlx->rmax - emlx->rmin); //maping
			// emlx->c.i = emlx->imin + (emlx->y + emlx->ud) / (double)emlx->H * (emlx->imax - emlx->imin);
			emlx->z.r = emlx->rmin + (emlx->x + emlx->lr) / (double)emlx->W * (emlx->rmax - emlx->rmin);
			emlx->z.i = emlx->imin + (emlx->y + emlx->ud) / (double)emlx->H * (emlx->imax - emlx->imin);
			emlx->new_z = emlx->z;
			while (calcul_c(emlx->z.r, emlx->z.i) < 4 && emlx->iter < emlx->maxiter)
			{
				emlx->new_z.r = (puissance_2(emlx->z.r) - puissance_2(emlx->z.i)) + emlx->c.r;
				emlx->new_z.i = (2 * emlx->z.r * emlx->z.i) + emlx->c.i;
				emlx->z = emlx->new_z;
				emlx->iter++;
			}
			if (emlx->iter == emlx->maxiter)
				emlx->color = 0;
			else
				emlx->color = emlx->customize_color * emlx->iter; //blue 
			// coloring(emlx);
			// mlx_pixel_put(mlx, win, x, y, color);
			emlx->image.addr[emlx->y * (int)emlx->W + emlx->x] = emlx->color;
			emlx->x++;
		}
		emlx->y++;
	}
}