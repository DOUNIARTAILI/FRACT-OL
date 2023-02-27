/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:50:21 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/27 01:50:47 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_bonus(t_mlx *emlx)
{
	emlx->y = 0;
	while (emlx->y < (int)emlx->hei)
	{
		emlx->x = 0;
		while (emlx->x < (int)emlx->wid)
		{
			emlx->iter = 1;
			emlx->c.r = emlx->mx;
			emlx->c.i = emlx->my;
			emlx->z.r = emlx->rmin + emlx->x
				/ (double)emlx->wid * (emlx->rmax - emlx->rmin);
			emlx->z.i = emlx->imin + emlx->y
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
