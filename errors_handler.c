/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:56:36 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/26 02:07:45 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	char	*str;

	write(1, "INVALID ARGUMENT !! \n", ft_strlen("INVALID ARGUMENT !! \n"));
	write(1, "To display mandelbrot enter ./fract-ol mandelbrot\n",
		ft_strlen("To display mandelbrot enter ./fract-ol mandelbrot\n"));
	write(1, "To display julia enter ./fract-ol julia\n",
		ft_strlen("To display julia enter ./fract-ol julia\n"));
	str = "To display julia by ur choice enter ./fract-ol julia /cr /ci\n";
	write(1, str, ft_strlen(str));
	write(1, "Exemple : ./fract-ol julia 0.285 0.01\n",
		ft_strlen("Exemple : ./fract-ol julia 0.285 0.01\n"));
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
