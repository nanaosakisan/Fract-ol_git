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

static int	algorithm(float y1, float x1, int x, int y, float zoom_x, float zoom_y, t_global *global)
{
	int		i;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	tmp;

	i = 0;
	c_r = x / zoom_x + x1;
	c_i = y / zoom_y + y1;
	z_r = 0;
	z_i = 0;
	while ((z_r * z_r + z_i * z_i < 4) && i < I_MAX)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp - c_i;
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
	float	y1;
	float	y2;
	float	x1;
	float	x2;
	int		x;
	int		y;
	int 	image_x;
	int		image_y;
	float	zoom_x;
	float	zoom_y;

	y1 = -1.2;
	y2 = 1.2;
	image_y = (y2 - y1) * ZOOM;
	x1 = -2.1;
	x2 = 0.6;
	image_x = (x2 - x1) * ZOOM;
	x = -1;
	zoom_x = image_x / (x2 - x1);
	zoom_y = image_y / (y2 - y1);
	while (++x < image_x)
	{
		y = -1;
		while (++y < image_x)
			algorithm(y1, x1, x, y, zoom_x, zoom_y, global);
	}
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	return (0);
}
