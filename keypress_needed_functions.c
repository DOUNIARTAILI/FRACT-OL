/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:46:44 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/27 00:59:09 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	cust_color_button(t_mlx *emlx, int keycode)
{
	static int	i;

	if (i == 6)
	{
		i = 0;
	}
	if (keycode == 18 && emlx && i < 6)
	{
		if (i == 0)
			emlx->customize_color = 0xDDDDFF;
		else if (i == 1)
			emlx->customize_color = 0x4c4c4c;
		else if (i == 2)
			emlx->customize_color = 0xff0066;
		else if (i == 3)
			emlx->customize_color = 0xFFD700;
		else if (i == 4)
			emlx->customize_color = 0x6f00ff;
		else if (i == 5)
			emlx->customize_color = 0x00CED1;
		i++;
	}
}

void	move_shape(t_mlx *emlx, int keycode)
{
	if (keycode == 123 && emlx)
	{
		emlx->lr += 10;
	}
	else if (keycode == 124 && emlx)
	{
		emlx->lr -= 10;
	}
	else if (keycode == 125 && emlx)
	{
		emlx->ud -= 10;
	}
	else if (keycode == 126 && emlx)
	{
		emlx->ud += 10;
	}
}
