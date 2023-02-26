/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:43:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/26 01:50:58 by drtaili          ###   ########.fr       */
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
	if (ft_strcmp(argv[1], "mandelbrot") == 0
		|| ft_strcmp(argv[1], "julia") == 0)
	{
		if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
		{
			emlx->mx = ft_atof(argv[2]);
			emlx->my = ft_atof(argv[3]);
		}
		emlx->tag = 0;
		draw(argv[1], emlx);
	}
	free(emlx);
	return (0);
}
