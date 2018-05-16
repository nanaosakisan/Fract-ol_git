/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:28:40 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/15 14:28:43 by iporsenn         ###   ########.fr       */
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
	global->fract[global->id].zoom_x = global->fract[global->id].img_x / \
				(global->fract[global->id].x2 - global->fract[global->id].x1);
	global->fract[global->id].zoom_y = global->fract[global->id].img_y / \
				(global->fract[global->id].y2 - global->fract[global->id].y1);
	while (++start < WIDTH && start < end && start < global->fract[global->id].img_x)
	{
		i = -1;
		while (++i < HEIGHT && i < global->fract[global->id].img_y)
			global->fract[global->id].function(x, y, global);
	}
	return (NULL);
}

int		select_fract(t_global *global)
{
	int i;

	if (!global->img.p_mlx)
	{
		global.img.p_mlx = mlx_init();
		global.img.p_win = mlx_new_window(global.img.p_mlx, WIDTH, HEIGHT, \
															global.name);
	}
	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, \
					&global->img.bpp, &global->img.size, &global->img.endian);
	global->fract[global->id].img_y = (global->fract[global->id].y2 - \
								global->fract[global->id].y1) * global->zoom;
	global->fract[global->id].img_x = (global->fract[global->id].x2 - \
								global->fract[global->id].x1) * global->zoom;
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
