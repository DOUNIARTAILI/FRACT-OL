/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:46:44 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/25 21:15:41 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cust_color_button(t_mlx *emlx, int keycode)
{
	static int	i;

	if (keycode == 18 && emlx && i < 6)
	{
		if (i == 0)
			emlx->customize_color = 0xDDDDFF;
		else if (i == 1)
			emlx->customize_color = 0x4c4c4c;
		else if (i == 2)
			emlx->customize_color = 0xff0066;
		else if (i == 3)
			emlx->customize_color = 0xffffff;
		else if (i == 4)
			emlx->customize_color = 0x6f00ff;
		else if (i == 5)
			emlx->customize_color = 0x00ff5f;
		i++;
	}
	if (i == 6)
	{
		i = 0;
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
