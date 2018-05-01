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
	int tmp_y;
	int tmp_x;

	tmp_x = x - global->pos[1];
	tmp_y = y - global->pos[0];
	printf("1 -> pos[0] = %d; pos[1] = %d\n", global->pos[0], global->pos[1]);
	printf("1 -> y = %d, x = %d\n", y, x);
	if (key != 1 && key != 2 && !x && !y)
		return (0);
	else if (key == 1)
	{
		global->move[1] += (tmp_x - global->mandel.img_x / 2) / global->zoom;
		global->move[0] += (tmp_y - global->mandel.img_y / 2) / global->zoom;
		global->zoom *= 1.25;
		global->move[1] -= (tmp_x - global->mandel.img_x / 2) / global->zoom;
		global->move[0] -= (tmp_y - global->mandel.img_y / 2) / global->zoom;
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
