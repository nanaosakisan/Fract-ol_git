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

int		pointed_zoom(int key, int x, int y, t_global *global)
{
	double tmp_x[2];
	double tmp_y[2];

	tmp_x[0] = global->fract[global->id].x1 + x * (global->fract[global->id].x2 - global->fract[global->id].x1) \
																		/ WIDTH;
	tmp_y[0] = global->fract[global->id].y1 + y * (global->fract[global->id].y2 - global->fract[global->id].y1) \
																	/ HEIGHT;
	tmp_x[1] = global->fract[global->id].x1;
	tmp_y[1] = global->fract[global->id].y1;
	if (key != 1 && key != 2 && !x && !y)
		return (0);
	else if (key == 1)
	{
		global->zoom *= 1.5;
		global->fract[global->id].x1 = tmp_x[0] - (global->fract[global->id].x2 - global->fract[global->id].x1) \
																			/ 3;
		global->fract[global->id].x2 = tmp_x[0] + (global->fract[global->id].x2 - tmp_x[1]) / 3;
		global->fract[global->id].y1 = tmp_y[0] - (global->fract[global->id].y2 - global->fract[global->id].y1) \
																			/ 3;
		global->fract[global->id].y2 = tmp_y[0] + (global->fract[global->id].y2 - tmp_y[1]) / 3;
		global->iter_max++;
	}
	else if (key == 2)
	{
		global->zoom /= 1.5;
		global->fract[global->id].x1 = tmp_x[0] - (global->fract[global->id].x2 - global->fract[global->id].x1);
		global->fract[global->id].x2 = tmp_x[0] + (global->fract[global->id].x2 - tmp_x[1]);
		global->fract[global->id].y1 = tmp_y[0] - (global->fract[global->id].y2 - global->fract[global->id].y1);
		global->fract[global->id].y2 = tmp_y[0] + (global->fract[global->id].y2 - tmp_y[1]);
		global->iter_max--;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		mouse_hook(int key, int x, int y, t_global *global)
{
	int i;

	i = 0;
	while (i < global->len_mouse && !global->mouse_func[i](key, x, y, global))
		i++;
	return (0);
}
