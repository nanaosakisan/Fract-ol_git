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

static int	get_thread_id(pthread_t id, pthread_t *thread)
{
	int i;

	i = 0;
	while (i < THREAD && !pthread_equal(id, thread[i]))
		i++;
	return (i);
}

static void	color(t_global *global, int x, int y, int i)
{

	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
																	0x000000);
	else if (i < global->iter_max / 2 - 1)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
		display_color(global, i, global->color.color[global->color.turn][0], \
									global->color.color[global->color.turn][1]));
	else if (i > global->iter_max / 2 && i < global->iter_max - 1)
		mlx_pixel_put_to_image(global, x + global->pos[1], y + global->pos[0], \
		display_color(global, i, global->color.color[global->color.turn][1], \
								global->color.color[global->color.turn][2]));
}

static int	algorithm(int x, int y, t_global *global)
{
	int			i;
	long double	z_r;
	long double	z_i;
	long double	tmp;

	i = 0;
	pthread_mutex_lock(&global->mandel.mutex);
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
	pthread_mutex_unlock(&global->mandel.mutex);
	color(global, x, y, i);
	return (0);
}

static void	*mandelbrot(void *data)
{
	int			start;
	int			end;
	int			padding;
	int			i;
	t_global	*global;

	global = (t_global *)data;
	padding = WIDTH / THREAD;
	start = get_thread_id(pthread_self(), global->thread) * padding;
	end = start + padding;
	while (++start < global->mandel.img_x && start + global->pos[1] < WIDTH \
			&& start < end)
	{
		i = -1;
		while (++i < global->mandel.img_y && i + global->pos[0] < HEIGHT)
			algorithm(start, i, global);
	}
	return (NULL);
}

int		launch_draw(t_global *global)
{
	global->img.p_img = mlx_new_image(global->img.p_mlx, WIDTH, HEIGHT);
	global->img.img_addr = mlx_get_data_addr(global->img.p_img, \
					&global->img.bpp, &global->img.size, &global->img.endian);
	global->mandel.img_y = (global->mandel.y2 - global->mandel.y1) * \
																global->zoom;
	global->mandel.img_x = (global->mandel.x2 - global->mandel.x1) * \
																global->zoom;
	global->mandel.zoom_x = global->mandel.img_x / (global->mandel.x2 - \
															global->mandel.x1);
	global->mandel.zoom_y = global->mandel.img_y / (global->mandel.y2 - \
															global->mandel.y1);
	init_pos(global);
	pthread_create(&global->thread[0], NULL, mandelbrot, global);
	pthread_create(&global->thread[1], NULL, mandelbrot, global);
	pthread_create(&global->thread[2], NULL, mandelbrot, global);
	pthread_create(&global->thread[3], NULL, mandelbrot, global);
	pthread_join(global->thread[0], NULL);
	pthread_join(global->thread[1], NULL);
	pthread_join(global->thread[2], NULL);
	pthread_join(global->thread[3], NULL);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
													global->img.p_img, 0, 0);
	// mandelbrot(global);
	return (0);
}
