/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:40:08 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/24 15:40:10 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	adjustment(int tmp_x, int tmp_y, t_global *global)
{
	float diff_x;
	float diff_y;

	diff_y = fabsl(tmp_y + global->fract[global->id].y1);
	diff_x = fabsl(tmp_x + global->fract[global->id].x1);
	global->fract[global->id].x2 += diff_x;
	global->fract[global->id].y2 += diff_y;
}

static void	zoom_in(int x, int y, t_global *global)
{
	float tmp[2];

	tmp[0] = global->fract[global->id].y1;
	tmp[1] = global->fract[global->id].x1;
	global->fract[global->id].x1 += (((float)x - (WIDTH / 2)) / \
															global->zoom);
	global->fract[global->id].y1 += (((float)y - (HEIGHT / 2)) / \
															global->zoom);
	adjustment(tmp[1], tmp[0], global);
	global->zoom *= 1.2;
	global->iter_max++;
}

static void	zoom_out(int x, int y, t_global *global)
{
	float tmp[2];

	tmp[0] = global->fract[global->id].y1;
	tmp[1] = global->fract[global->id].x1;
	global->fract[global->id].x1 -= (((float)x - (WIDTH / 2)) / \
															global->zoom);
	global->fract[global->id].y1 -= (((float)y - (HEIGHT / 2)) / \
															global->zoom);
	adjustment(tmp[1], tmp[0], global);
	global->zoom *= 0.8;
	global->iter_max--;
}

int			pointed_zoom(int key, int x, int y, t_global *global)
{
	if ((key != 1 && key != 2) || (!x && !y))
		return (0);
	else if (key == 1)
		zoom_in(x, y, global);
	else if (key == 2)
		zoom_out(x, y, global);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int			zoom_molette(int key, int x, int y, t_global *global)
{
	if ((key != 4 && key != 5) || (!x && !y))
		return (0);
	else if (key == 5)
		zoom_in(x, y, global);
	else if (key == 4)
		zoom_out(x, y, global);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}
