/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:35:19 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 01:40:50 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	puissance_2(double n)
{
	return (n * n);
}

double	calcul_c(double	zr, double zi)
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
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (ss1[i] || ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
int	ft_setup(char *str, t_mlx *emlx)
{
	if (ft_strncmp(str, "mandelbrot", ft_strlen("mandelbrot")) == 0 || ft_strncmp(str, "burningship", ft_strlen("burningship")) == 0)
	{
	emlx = (t_mlx *)malloc(sizeof(t_mlx));
	emlx->mlx = mlx_init();
	emlx->win = mlx_new_window(emlx->mlx, emlx->W, emlx->H, "mandelbrot");
	emlx->image.img = mlx_new_image(emlx->mlx, emlx->W, emlx->H);
	emlx->image.addr = (int*)mlx_get_data_addr(emlx->image.img, &emlx->image.bits_per_pixel, &emlx->image.line_length, &emlx->image.endian);
	return (1);
	}
		return (0);
}