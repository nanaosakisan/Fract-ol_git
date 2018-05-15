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

static int	get_thread_id(pthread_t id, pthread_t *thread)
{
	int i;

	i = 0;
	while (i < THREAD && !pthread_equal(id, thread[i]))
		i++;
	return (i);
}

static void algorithm(int x, int y, t_global *global)
{
	long double z[2];
	long double tmp;
	int			i;

	z[0] = x / global->fract[global->index].zoom_x + global->fract[global->index].x1;
	z[1] = y / global->fract[global->index].zoom_y + global->fract[global->index].y1;
	i = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + 0.285;
		z[1] = 2 * z[1] * tmp + 0.01;
		i++;
		if (i == global->iter_max)
			mlx_pixel_put_to_image(global, x, y, 0x4DCD32);
		else
			mlx_pixel_put_to_image(global, x, y, 0x000000);
	}
}

static void	*launch_thread(void *data)
{
	int			start;
	int			end;
	int			padding;
	int			i;
	t_global	*global;

	global = (t_global *)data;
	padding = WIDTH / THREAD;
	start = get_thread_id(pthread_self(), global->thread) * padding;
	end = start + padding + 1;
	while (++start < WIDTH && start < end)
	{
		i = -1;
		while (++i < HEIGHT)
			algorithm(start, i, global);
	}
	return (NULL);
}

int		launch_draw_julia(t_global *global)
{
	int i;

	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, \
					&global->img.bpp, &global->img.size, &global->img.endian);
	global->fract[global->index].img_y = (global->fract[global->index].y2 - \
								global->fract[global->index].y1) * global->zoom;
	global->fract[global->index].img_x = (global->fract[global->index].x2 - \
								global->fract[global->index].x1) * global->zoom;
	global->fract[global->index].zoom_x = global->fract[global->index].img_x / \
			(global->fract[global->index].x2 - global->fract[global->index].x1);
	global->fract[global->index].zoom_y = global->fract[global->index].img_y / \
			(global->fract[global->index].y2 - global->fract[global->index].y1);
	i = -1;
	while (++i < THREAD)
		pthread_create(&global->thread[i], NULL, launch_thread, global);
	i = -1;
	while (++i < THREAD)
		pthread_join(global->thread[i], NULL);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	return (0);
}
