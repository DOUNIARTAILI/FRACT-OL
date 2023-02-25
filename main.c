/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:43:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 01:00:09 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*emlx;

	if ((ft_strcmp(argv[1], "mandelbrot") == 0 || ft_strcmp(argv[1], "mandelbrot_bonus") == 0
		|| ft_strcmp(argv[1], "burningship_bonus") == 0) && (argc <= 1 || argc > 2))
		exit(0);
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ft_setup(argv[1], emlx) == 0)
	{
		// write(1, "INVALID ARGUMENT\n", ft_strlen("INVALID ARGUMENT\n"));
		exit (0);
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
	else if (ft_strcmp(argv[1], "mandelbrot_bonus") == 0
		|| ft_strcmp(argv[1], "burningship_bonus") == 0
		|| ft_strcmp(argv[1], "julia_bonus") == 0)
	{
		emlx->tag = 1;
		draw_bonus(argv[1], emlx);
	}	
	return (0);
}
