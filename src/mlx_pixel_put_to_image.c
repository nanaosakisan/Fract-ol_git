/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:39:42 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/19 13:39:44 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mlx_pixel_put_to_image(t_global *global, int x, int y, \
																	int color)
{
	int i;

	if (global->img.endian == 0)
	{
		i = (global->img.size * y) + (x * (global->img.bpp / 8));
		global->img.img_addr[i] = mlx_get_color_value(global->img.p_mlx, color);
		global->img.img_addr[i + 1] = mlx_get_color_value(global->img.p_mlx, \
																	color >> 8);
		global->img.img_addr[i + 2] = mlx_get_color_value(global->img.p_mlx, \
																color >> 16);
	}
	else
	{
		i = (global->img.size * y) + (x * (global->img.bpp / 8));
		global->img.img_addr[i] = mlx_get_color_value(global->img.p_mlx, \
																color >> 16);
		global->img.img_addr[i + 1] = mlx_get_color_value(global->img.p_mlx, \
																	color >> 8);
		global->img.img_addr[i + 2] = mlx_get_color_value(global->img.p_mlx, \
																		color);
	}
}
