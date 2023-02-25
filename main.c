/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:43:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 23:34:41 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(1, "INVALID ARGUMENT !! \n", ft_strlen("INVALID ARGUMENT !! \n"));
	write(1, "To display mandelbrot enter ./fract-ol mandelbrot\n",
		ft_strlen("To display mandelbrot enter ./fract-ol mandelbrot\n"));
	write(1, "To display julia enter ./fract-ol julia\n",
		ft_strlen("To display julia enter ./fract-ol julia\n"));
	write(1, "To display julia by ur choice enter ./fract-ol julia /cr /ci\n",
		ft_strlen("To display julia by ur choice enter./fract-ol julia /cr /ci\n"));
	write(1, "Exemple julia set : cr = 0.285 ci = 0.01\n",
		ft_strlen("Exemple julia set : cr = 0.285 ci = 0.01\n"));
	write(1, "To display burningship enter ./fract-ol burningship\n",
		ft_strlen("To display burningship enter ./fract-ol burningship\n"));
	write(1, "Thank u :)\n", ft_strlen("Thank u :)\n"));
	exit (0);
}

void	check_errors(char *str, int ac)
{
	if (ac == 1)
		ft_error();
	if ((ft_strcmp(str, "mandelbrot") == 0
			|| ft_strcmp(str, "mandelbrot_bonus") == 0
			|| ft_strcmp(str, "burningship") == 0)
		&& (ac <= 1 || ac > 2))
		ft_error();
	if ((ft_strcmp(str, "julia_bonus") == 0
			|| ft_strcmp(str, "julia") == 0)
		&& (ac <= 1 || ac > 4 || ac == 3))
		ft_error();
}

void	suite_main(char *str, t_mlx *emlx)
{
	emlx->tag = 1;
	draw_bonus(str, emlx);
}

int	main(int argc, char **argv)
{
	t_mlx	*emlx;

	check_errors(argv[1], argc);
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ft_setup(argv[1], emlx) == 0)
		ft_error();
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
		|| ft_strcmp(argv[1], "burningship") == 0
		|| ft_strcmp(argv[1], "julia_bonus") == 0)
		suite_main(argv[1], emlx);
	return (0);
}
