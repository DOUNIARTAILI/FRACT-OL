/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:17:58 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 21:09:55 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_point{
	double	r;
	double	i;
}t_point;

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	t_point	c;
	t_point	z;
	t_data	image;
	t_point	new_z;
	double	mx;
	double	my;
	double	imin;
	double	imax;
	double	rmin;
	double	rmax;
	double	zoom;
	void	*mlx;
	void	*win;
	int		x;
	int		color;
	int		customize_color;
	int		y;
	int		iter;
	int		maxiter;
	int		wid;
	int		hei;
	int		id;
	int		ud;
	int		lr;
	int		tag;
	int		m;
}t_mlx;

void	ft_mandelbrot(t_mlx *emlx);
void	ft_mandelbrot_bonus(t_mlx *emlx);
void	ft_burningship(t_mlx *emlx);
void	ft_julia(t_mlx *emlx);
void	ft_julia_bonus(t_mlx *emlx);
void	draw(char *str, t_mlx *emlx);
int		ft_close(void *param);
int		key_press(int keycode, t_mlx *emlx);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
double	puissance_2(double n);
double	calcul_c(double zr, double zi);
int		ft_setup(char *str, t_mlx *emlx);
void	ft_init(t_mlx *emlx);
void	ft_zoom(t_mlx *emlx, int button, int x, int y);
void	escaped_or_not(t_mlx *emlx);
void	burningship_z(t_mlx *emlx);
void	color_it(t_mlx *emlx);
void	move_shape(t_mlx *emlx, int keycode);
void	cust_color_button(t_mlx *emlx, int keycode);
void	ft_clearwindow(t_mlx *emlx);
void	draw_bonus(char *str, t_mlx *emlx);
double	ft_atof(const char *str);
void	ft_error(void);

#endif