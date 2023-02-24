/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:46:44 by drtaili           #+#    #+#             */
/*   Updated: 2023/02/24 20:47:02 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cust_color_button(t_mlx *emlx, int keycode)
{
	if (keycode == 18 && emlx)
	{
		emlx->customize_color = 0xBE25BE;
	}
	else if (keycode == 19 && emlx)
	{
		emlx->customize_color = 0x25BE48;
	}
	else if (keycode == 20 && emlx)
	{
		emlx->customize_color = 0x7D797A;
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
