/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:55 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 15:57:02 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// int		move_up_and_down(t_global *global, int key)
// {
// 	if (key != 125 && key != 126)
// 		return (0);
// 	else if (key == 126)
// 		global->coords.move[0] = global->coords.move[0] - 10;
// 	else if (key == 125)
// 		global->coords.move[0] = global->coords.move[0] + 10;
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }
//
// int		move_right_and_left(t_global *global, int key)
// {
// 	if (key != 124 && key != 123)
// 		return (0);
// 	else if (key == 124)
// 		global->coords.move[1] = global->coords.move[1] + 10;
// 	else if (key == 123)
// 		global->coords.move[1] = global->coords.move[1] - 10;
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }
//
// int		init_map(t_global *global, int key)
// {
// 	if (key != 82)
// 		return (0);
// 	global->pad = global->tmp.pad;
// 	global->pad_z = global->tmp.pad_z;
// 	global->coords.move[0] = 0;
// 	global->coords.move[1] = 0;
// 	global->coords.angle_x = 0.2;
// 	global->coords.angle_y = -0.1;
// 	global->coords.angle_z = 0;
// 	global->coords.color = 0xFFFFFF;
// 	init_pos(global);
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }

int		close_map(t_global *global, int key)
{
	if (key != 53)
		return (0);
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	global->img.p_mlx = NULL;
	global->img.p_win = NULL;
	global->img.p_img = NULL;
	global->img.img_addr = NULL;
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_global *global)
{
	int i;

	i = 0;
	while ((i < global->len_array) && !global->function[i](global, key))
		i++;
	return (0);
}
