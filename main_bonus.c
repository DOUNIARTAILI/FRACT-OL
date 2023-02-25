/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:54:37 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 23:56:23 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (ft_strcmp(argv[1], "mandelbrot_bonus") == 0
		|| ft_strcmp(argv[1], "burningship") == 0
		|| ft_strcmp(argv[1], "julia_bonus") == 0)
		suite_main(argv[1], emlx);
	return (0);
}
