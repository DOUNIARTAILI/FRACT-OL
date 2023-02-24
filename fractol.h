# ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct s_point{
	double r;
	double i;
}t_point;

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length; 
	int		endian;
}				t_data;

typedef	struct s_mlx
{
	t_point	c;
	t_point	z;
	t_data	image;
	t_point	new_z;
	double mx;
	double my;
	double imin;
	double imax;
	double rmin;
	double rmax;
	double zoom;
	void *mlx;
	void *win;
	int x;
	int color;
	int y;
	int iter;
	int maxiter;
	int W;
	int H;
	int id;
	int ud;
	int lr;
}t_mlx;

void	ft_mandelbrot(t_mlx *emlx);
void	ft_burningship(t_mlx *emlx);


void	draw(char *str, t_mlx *emlx);
int close(void *param);
int key_press(int keycode, t_mlx *par);
int mouse_press(int button, int x, int y, void *param);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	puissance_2(double n);
double	calcul_c(double	zr, double zi);
int	ft_setup(char *str, t_mlx *emlx);
void	ft_init(t_mlx *emlx);
void	ft_zoom(t_mlx *emlx, int button, int x, int y);


#endif