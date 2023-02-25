/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:41:31 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 21:16:23 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_mlx *e, double mousere, double mouseim)
{
	e->rmin = interpolate(mousere, e->rmin, e->zoom);
	e->imin = interpolate(mouseim, e->imin, e->zoom);
	e->rmax = interpolate(mousere, e->rmax, e->zoom);
	e->imax = interpolate(mouseim, e->imax, e->zoom);
}

void	ft_zoom(t_mlx *emlx, int button, int x, int y)
{
	double	mousere;
	double	mouseim;

	if (button == 5)
		emlx->zoom = 0.8;
	else if (button == 4)
		emlx->zoom = 1.2;
	mousere = (double)x / (emlx->wid / (emlx->rmax - emlx->rmin)) + emlx->rmin;
	mouseim = (double)y / (emlx->hei / (emlx->imax - emlx->imin)) + emlx->imin;
	if (emlx->m == 1)
	{
		mousere = (double)(emlx->wid / 2)
			/ (emlx->wid / (emlx->rmax - emlx->rmin)) + emlx->rmin;
		mouseim = (double)(emlx->hei / 2)
			/ (emlx->hei / (emlx->imax - emlx->imin)) + emlx->imin;
	}
	applyzoom(emlx, mousere, mouseim);
}
