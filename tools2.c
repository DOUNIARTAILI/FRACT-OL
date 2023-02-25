/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:35:19 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 21:15:54 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	puissance_2(double n)
{
	return (n * n);
}

double	calcul_c(double zr, double zi)
{
	return (puissance_2(zr) + puissance_2(zi));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_setup(char *str, t_mlx *emlx)
{
	if (ft_strcmp(str, "mandelbrot") == 0
		|| ft_strcmp(str, "julia") == 0
		|| ft_strcmp(str, "mandelbrot_bonus") == 0
		|| ft_strcmp(str, "burningship") == 0
		|| ft_strcmp(str, "julia_bonus") == 0)
	{
		emlx = (t_mlx *)malloc(sizeof(t_mlx));
		emlx->mlx = mlx_init();
		emlx->win = mlx_new_window(emlx->mlx, emlx->wid, emlx->hei, "fract-ol");
		emlx->image.img = mlx_new_image(emlx->mlx, emlx->wid, emlx->hei);
		emlx->image.addr = (int *)mlx_get_data_addr(emlx->image.img,
				&emlx->image.bits_per_pixel, &emlx->image.line_length,
				&emlx->image.endian);
		return (1);
	}
	return (0);
}
