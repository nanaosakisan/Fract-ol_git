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

int			pointed_zoom(int key, int x, int y, t_global *global)
{
	float tmp[2];

	tmp[0] = global->fract[global->id].y1;
	tmp[1] = global->fract[global->id].x1;
	if ((key != 1 && key != 2) || (!x && !y))
		return (0);
	else if (key == 1)
	{
		global->fract[global->id].x1 += (((float)x - (WIDTH / 2)) / global->zoom);
		global->fract[global->id].y1 += (((float)y - (HEIGHT / 2)) / global->zoom);
		adjustment(tmp[1], tmp[0], global);
		global->zoom *= 1.2;
		global->iter_max++;
	}
	else if (key == 2)
	{
		global->fract[global->id].x1 -= (((float)x - (WIDTH / 2)) / global->zoom);
		global->fract[global->id].y1 -= (((float)y - (HEIGHT / 2)) / global->zoom);
		adjustment(tmp[1], tmp[0], global);
		global->zoom *= 0.8;
		global->iter_max--;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		zoom_molette(int key, int x, int y, t_global *global)
{
	float tmp[2];

	tmp[0] = global->fract[global->id].y1;
	tmp[1] = global->fract[global->id].x1;
	if ((key != 4 && key != 5) || (!x && !y))
		return (0);
	else if (key == 5)
	{
		global->fract[global->id].x1 += (((float)x - (WIDTH / 2)) / global->zoom);
		global->fract[global->id].y1 += (((float)y - (HEIGHT / 2)) / global->zoom);
		adjustment(tmp[1], tmp[0], global);
		global->zoom *= 1.2;
		global->iter_max++;
	}
	else if (key == 4)
	{
		global->fract[global->id].x1 -= (((float)x - (WIDTH / 2)) / global->zoom);
		global->fract[global->id].y1 -= (((float)y - (HEIGHT / 2)) / global->zoom);
		adjustment(tmp[1], tmp[0], global);
		global->zoom *= 0.8;
		global->iter_max--;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		mouse_position(int x, int y, t_global *global)
{
	if (global->fract[1].turn == 1)
	{
		global->fract[1].c[0] = (global->fract[1].c[0] + y) / 1000;
		global->fract[1].c[1] = (global->fract[1].c[1] + x) / 1000;
		// printf("c[0] = %Lf, c[1] = %Lf\n", global->fract[1].c[0], global->fract[1].c[1]);
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		select_fract(global);
	}
	else
		return (0);
	return (1);
}

int		turn_fract(int key, int x, int y, t_global *global)
{
	if ((key != 3) || (!x && !y))
		return (0);
	else if (key == 3)
	{
		global->zoom = 230;
		global->id += (global->id < 3) ? 1 : -3;
	}
	init_tmp(global);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		mouse_hook(int key, int x, int y, t_global *global)
{
	int i;

	i = 0;
	while ((i < global->len_mouse) && !global->mouse_func[i](key, x, y, global))
		i++;
	return (0);
}
