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
	if (key != 1 && key != 2 && !x && !y)
		return (0);
	else if (key == 1)
	{
		global->mandel.x2 = x;
		global->mandel.y2 = y;
		global->mandel.x1 = (x / global->zoom + global->mandel.x1) - ((global->zoom * 1.3) / 2);
		global->mandel.x1 += ((global->zoom * 1.3) / 2) - (x / (global->zoom * 1.3));
		global->mandel.y1 = (y / global->zoom + global->mandel.y1) - ((global->zoom * 1.3) / 2);
		global->mandel.y1 += ((global->zoom * 1.3) / 2) - (y / (global->zoom * 1.3));
		global->zoom *= 1.3;
	}
	else if (key == 2)
		global->zoom -= 10;
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	launch_draw(global);
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
// data->x2 = x;
// data->y2 = y;
// data->x1 = (x / data->zoom + data->x1) - ((data->zoom * 1.3) / 2);
// data->x1 += ((data->zoom * 1.3) / 2) - (x / (data->zoom * 1.3));
// data->y1 = (y / data->zoom + data->y1) - ((data->zoom * 1.3) / 2);
// data->y1 += ((data->zoom * 1.3) / 2) - (y / (data->zoom * 1.3));
// data->zoom *= 1.3;
// data->it_max++;
