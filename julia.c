/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:42:41 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 00:38:36 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_mlx *emlx)
{
	emlx->y = 0;
	while (emlx->y < (int)emlx->hei)
	{
		emlx->x = 0;
		while (emlx->x < (int)emlx->wid)
		{
			emlx->iter = 1;
			// emlx->c.r = emlx->rmin + emlx->mx
			// 	/ (double)emlx->wid * (emlx->rmax - emlx->rmin);
			// emlx->c.i = emlx->imin + emlx->my
			// 	/ (double)emlx->hei * (emlx->imax - emlx->imin);
			emlx->c.r = emlx->mx;
			emlx->c.i = emlx->my;
			emlx->z.r = emlx->rmin + (emlx->x + emlx->lr)
				/ (double)emlx->wid * (emlx->rmax - emlx->rmin);
			emlx->z.i = emlx->imin + (emlx->y + emlx->ud)
				/ (double)emlx->hei * (emlx->imax - emlx->imin);
			emlx->new_z = emlx->z;
			escaped_or_not(emlx);
			color_it(emlx);
			emlx->image.addr[emlx->y * (int)emlx->wid + emlx->x] = emlx->color;
			emlx->x++;
		}
		emlx->y++;
	}
}
