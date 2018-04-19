/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:22:56 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/13 15:23:02 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	algorithm(int x, int y, t_global *global)
{
	int			i;
	long double	z_r;
	long double	z_i;
	long double	tmp;

	i = 0;
	global->mandel.c_r = x / global->mandel.zoom_x + global->mandel.x1;
	global->mandel.c_i = y / global->mandel.zoom_y + global->mandel.y1;
	z_r = 0;
	z_i = 0;
	while ((z_r * z_r + z_i * z_i < 4) && i < I_MAX)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + global->mandel.c_r;
		z_i = 2 * z_i * tmp - global->mandel.c_i;
		i++;
	}
	if (i == I_MAX)
		mlx_pixel_put_to_image(global, x, y, 0xFFFFFF);
	else if (i >1)
		mlx_pixel_put_to_image(global, x, y, 0x000000);
	return (0);
}

int		mandelbrot(t_global *global)
{
	int			x;
	int			y;

	x = -1;
	global->mandel.img_y = (global->mandel.y2 - global->mandel.y1) * \
																global->zoom;
	global->mandel.img_x = (global->mandel.x2 - global->mandel.x1) * \
																global->zoom;
	global->mandel.zoom_x = global->mandel.img_x / (global->mandel.x2 - \
															global->mandel.x1);
	global->mandel.zoom_y = global->mandel.img_y / (global->mandel.y2 - \
															global->mandel.y1);
	while (++x < global->mandel.img_x && x <= WIDTH)
	{
		y = -1;
		while (++y < global->mandel.img_y && y <= HEIGHT)
			algorithm(x, y, global);
	}
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	return (0);
}
