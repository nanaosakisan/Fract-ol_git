/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:30:40 by iporsenn          #+#    #+#             */
/*   Updated: 2018/06/04 11:30:46 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_position(int x, int y, t_global *global)
{
	if (global->fract[1].turn == 1)
	{
		global->fract[1].c[0] = (global->fract[1].c[0] + y) / 1000;
		global->fract[1].c[1] = (global->fract[1].c[1] + x) / 1000;
		mlx_destroy_image(global->img.p_mlx, global->img.p_img);
		select_fract(global);
	}
	else
		return (0);
	return (1);
}

int			turn_fract(int key, int x, int y, t_global *global)
{
	if ((key != 3) || (!x && !y))
		return (0);
	else if (key == 3)
	{
		global->iter_max = global->tmp.iter_max;
		global->zoom = global->tmp.zoom;
		global->fract[global->id].x1 = global->tmp.x1;
		global->fract[global->id].y1 = global->tmp.y1;
		global->fract[global->id].x2 = global->tmp.x2;
		global->fract[global->id].y2 = global->tmp.y2;
		global->id += (global->id < 3) ? 1 : -3;
	}
	init_tmp(global);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int			mouse_hook(int key, int x, int y, t_global *global)
{
	int i;

	i = 0;
	while ((i < global->len_mouse) && !global->mouse_func[i](key, x, y, global))
		i++;
	return (0);
}
