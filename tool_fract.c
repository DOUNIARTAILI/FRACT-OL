/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:32:46 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 23:45:07 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	escaped_or_not(t_mlx *emlx)
{
	while (calcul_c(emlx->z.r, emlx->z.i) < 4
		&& emlx->iter < emlx->maxiter)
	{
		emlx->new_z.r = (puissance_2(emlx->z.r)
				- puissance_2(emlx->z.i)) + emlx->c.r;
		emlx->new_z.i = (2 * emlx->z.r * emlx->z.i) + emlx->c.i;
		emlx->z = emlx->new_z;
		emlx->iter++;
	}
}

void	burningship_z(t_mlx *emlx)
{
	while (calcul_c(emlx->z.r, emlx->z.i) < 4
		&& emlx->iter < emlx->maxiter)
	{
		emlx->new_z.r = fabs((puissance_2(emlx->z.r)
				- puissance_2(emlx->z.i)) + emlx->c.r);
		emlx->new_z.i = fabs((2 * emlx->z.r * emlx->z.i) + emlx->c.i);
		emlx->z = emlx->new_z;
		emlx->iter++;
	}
}

void	color_it(t_mlx *emlx)
{
	if (emlx->iter == emlx->maxiter)
		emlx->color = 0;
	else
		emlx->color = emlx->customize_color * emlx->iter;
}
