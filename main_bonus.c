/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:54:37 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/27 01:25:33 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*emlx;

	check_errors(argv[1], argc);
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ft_setup(argv[1], emlx) == 0)
	{
		ft_error();
		free(emlx);
	}
	ft_init(emlx);
	if (ft_strcmp(argv[1], "mandelbrot_bonus") == 0
		|| ft_strcmp(argv[1], "burningship") == 0
		|| ft_strcmp(argv[1], "julia_bonus") == 0)
	{
		if (ft_strcmp(argv[1], "julia_bonus") == 0 && argc == 4)
		{
			emlx->mx = ft_atof(argv[2]);
			emlx->my = ft_atof(argv[3]);
		}
		emlx->tag = 1;
		draw_bonus(argv[1], emlx);
	}
	free(emlx);
	return (0);
}
