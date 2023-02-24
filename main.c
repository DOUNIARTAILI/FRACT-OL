/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:43:23 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 20:08:46 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*emlx;

	if (argc <= 1 || argc > 2)
		exit(0);
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ft_setup(argv[1], emlx) == 0)
		exit (0);
	ft_init(emlx);
	draw(argv[1], emlx);
	return (0);
}
