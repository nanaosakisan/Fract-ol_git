/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:06:49 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/14 15:06:51 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// static int	get_thread_id(pthread_t id, pthread_t *thread)
// {
// 	int i;
//
// 	i = 0;
// 	while (i < THREAD && !pthread_equal(id, thread[i]))
// 		i++;
// 	return (i);
// }

static void algorithm(int x, int y, t_global *global)
{
	long double c[2];
	long double z[2];
	long double tmp;
	int			i;

	c[0] = 0.285;
	c[1] = 0.01;
	z[0] = x / global->julia.zoom_x + global->julia.x1;
	z[1] = y / global->julia.zoom_y + global->julia.y1;
	i = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
		ft_putnbr_endl(i);
	}
	if (i == global->iter_max)
	{
		ft_putendl("white ");
		mlx_pixel_put_to_image(global, x, y, 0xFFFFFF);
	}
	else
		mlx_pixel_put_to_image(global, x, y, 0x000000);
}

// static void	*launch_thread(void *data)
// {
// 	int			start;
// 	int			end;
// 	int			padding;
// 	int			i;
// 	t_global	*global;
//
// 	global = (t_global *)data;
// 	padding = WIDTH / THREAD;
// 	start = get_thread_id(pthread_self(), global->thread) * padding;
// 	end = start + padding + 1;
// 	while (++start < WIDTH && start < end)
// 	{
// 		i = -1;
// 		while (++i < HEIGHT)
// 			algorithm(start, i, global);
// 	}
// 	return (NULL);
// }

int		launch_draw_julia(t_global *global)
{
	int x;
	int y;

	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, \
					&global->img.bpp, &global->img.size, &global->img.endian);
	global->julia.img_y = (global->julia.y2 - global->julia.y1) * \
																global->zoom;
	global->julia.img_x = (global->julia.x2 - global->julia.x1) * \
																global->zoom;
	global->julia.zoom_x = global->julia.img_x / (global->julia.x2 - \
															global->julia.x1);
	global->julia.zoom_y = global->julia.img_y / (global->julia.y2 - \
															global->julia.y1);
	x = -1;
	while (++x < global->julia.img_x && x < WIDTH)
	{
		// ft_putendl("nyup");
		y = -1;
		while (++y < global->julia.img_y && y < HEIGHT)
			algorithm(x, y, global);
	}
	return (0);
}
