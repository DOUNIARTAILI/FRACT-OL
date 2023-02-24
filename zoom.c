/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:41:31 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 03:34:06 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void applyZoom(t_mlx *e, double mouseRe, double mouseIm)
{
     e->rmin = interpolate(mouseRe, e->rmin, e->zoom);
     e->imin = interpolate(mouseIm, e->imin, e->zoom);
     e->rmax = interpolate(mouseRe, e->rmax, e->zoom);
     e->imax = interpolate(mouseIm, e->imax, e->zoom);
}

void	ft_zoom(t_mlx *emlx, int button, int x, int y)
{
	double mouseRe;
	double mouseIm;
	
	if (button == 5)
		emlx->zoom = 0.8;
	else if (button == 4)
		emlx->zoom = 1.2;
	mouseRe = (double)x / (emlx->W / (emlx->rmax - emlx->rmin)) + emlx->rmin;
	mouseIm = (double)y / (emlx->H / (emlx->imax - emlx->imin)) + emlx->imin;
	// printf("mx=%f, my=%f\n", mouseRe, mouseIm);
	applyZoom(emlx, mouseRe, mouseIm);
}