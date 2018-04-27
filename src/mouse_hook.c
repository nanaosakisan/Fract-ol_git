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
		global->mandel.y1 += 0.10;
		global->mandel.y2 -= 0.10;
		global->mandel.x1 += 0.10;
		global->mandel.x2 -= 0.10;
	}
	else if (key == 2)
	{
		global->mandel.y1 -= 0.10;
		global->mandel.y2 += 0.10;
		global->mandel.x1 -= 0.10;
		global->mandel.x2 += 0.10;
	}
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
