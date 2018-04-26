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

static void	init_pos(t_global *global)
{
	global->pos[0] = (HEIGHT / 2 - global->mandel.img_y / 2) + global->move[0];
	global->pos[1] = (WIDTH / 2 - global->mandel.img_x / 2) + global->move[1];
}

static int	algorithm(int x, int y, t_global *global)
{
	int			i;
	long double	z_r;
	long double	z_i;
	long double	tmp;
	// pthread_t	thread1;

	i = 0;
	global->mandel.c_r = (x / global->mandel.zoom_x + global->mandel.x1);
	global->mandel.c_i = (y / global->mandel.zoom_y + global->mandel.y1);
	z_r = 0;
	z_i = 0;
	while ((z_r * z_r + z_i * z_i < 4) && i < global->iter_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + global->mandel.c_r;
		z_i = 2 * z_i * tmp - global->mandel.c_i;
		i++;
	}
	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
																	0x000000);
	else if (i < global->iter_max / 2 - 1)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
								display_color(global, i, 0x000000, 0xFE93FF));
	else if (i > global->iter_max / 2 && i < global->iter_max - 1)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
								display_color(global, i, 0xFE93FF, 0xFFFFFF));
	return (0);
}

int		mandelbrot(t_global *global)
{
	int	x;
	int	y;

	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, \
					&global->img.bpp, &global->img.size, &global->img.endian);
	x = -100;
	global->mandel.img_y = (global->mandel.y2 - global->mandel.y1) * \
																global->zoom;
	global->mandel.img_x = (global->mandel.x2 - global->mandel.x1) * \
																global->zoom;
	global->mandel.zoom_x = global->mandel.img_x / (global->mandel.x2 - \
															global->mandel.x1);
	global->mandel.zoom_y = global->mandel.img_y / (global->mandel.y2 - \
															global->mandel.y1);
	init_pos(global);
	while (++x < global->mandel.img_x + 100 && x + global->pos[1] < WIDTH)
	{
		y = -100;
		while (++y < global->mandel.img_y + 100 && y + global->pos[0] < HEIGHT)
			algorithm(x, y, global);
	}
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	return (0);
}
