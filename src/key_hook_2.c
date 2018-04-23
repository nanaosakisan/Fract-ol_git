/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:01 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 15:55:18 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				zoom(t_global *global, int key)
{
	if (key != 116 && key != 121)
		return (0);
	else if (key == 116)
		global->zoom = (global->zoom < 400) ? global->zoom * 1.5 : global->zoom;
	else if (key == 121)
		global->zoom = (global->zoom > 0) ? global->zoom * 0.85 : global->zoom;
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	mandelbrot(global);
	return (1);
}

int				iteration(t_global *global, int key)
{
	if (key != 69 && key != 78)
		return (0);
	else if (key == 78)
		global->iter_max += 10;
	else if (key == 69)
	{
		if (global->iter_max > 20)
			global->iter_max -= 10;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	mandelbrot(global);
	return (1);
}
