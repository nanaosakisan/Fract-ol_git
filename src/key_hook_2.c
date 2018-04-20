/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:02:01 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 15:55:18 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				zoom(t_global *global, int key)
{
	if (key != 116 && key != 121)
		return (0);
	else if (key == 116)
		global->zoom = (global->zoom < 400) ? global->zoom * 1.5 : global->zoom;
	else if (key == 121)
		global->zoom = (global->zoom > 0) ? global->zoom * 0.85 : global->zoom;
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	mandelbrot(global);
	return (1);
}

// int				zoom(t_fdf *global, int key)
// {
// 	float tmp;
//
// 	if (key != 116 && key != 121)
// 		return (0);
// 	tmp = global->pad;
// 	global->pad = (key == 116) ? global->pad * 1.5 : global->pad * 0.85;
// 	if (key == 116)
// 	{
// 		global->coords.pos[0] = global->coords.pos[0] - (((global->pad * \
// 								global->height) - (tmp * global->height)) / 2);
// 		global->coords.pos[1] = global->coords.pos[1] - (((global->pad * \
// 								global->width) - (tmp * global->width)) / 2);
// 	}
// 	else if (key == 121)
// 	{
// 		global->coords.pos[0] = global->coords.pos[0] - (((global->pad * \
// 							global->height) - (tmp * global->height)) / 2);
// 		global->coords.pos[1] = global->coords.pos[1] - (((global->pad * \
// 							global->width) - (tmp * global->width)) / 2);
// 	}
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }

// int				rotation_z(t_fdf *global, int key)
// {
// 	static int	cpt;
//
// 	if (key != 256 && key != 47 && key != 43)
// 		return (0);
// 	else if (key == 256)
// 		cpt += (cpt == 2) ? -2 : 1;
// 	else if (key == 47)
// 	{
// 		global->coords.angle_x += (cpt == 0) ? 0.1 : 0;
// 		global->coords.angle_y += (cpt == 1) ? 0.1 : 0;
// 		global->coords.angle_z += (cpt == 2) ? 0.1 : 0;
// 	}
// 	else if (key == 43)
// 	{
// 		global->coords.angle_x -= (cpt == 0) ? 0.1 : 0;
// 		global->coords.angle_y -= (cpt == 1) ? 0.1 : 0;
// 		global->coords.angle_z -= (cpt == 2) ? 0.1 : 0;
// 	}
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }
//
// int				increase_decrease_z(t_fdf *global, int key)
// {
// 	if (key != 69 && key != 78)
// 		return (0);
// 	else if (key == 69)
// 		global->pad_z = global->pad_z + 1;
// 	else if (key == 78)
// 		global->pad_z = global->pad_z - 1;
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }
//
// int				display_color(t_fdf *global, int key)
// {
// 	if (key != 83 && key != 85 && key != 86 && key != 88 && key != 89 \
// 																&& key != 92)
// 		return (0);
// 	else if (key == 89 || key == 92)
// 		(key == 92) ? (global->coords.color = global->coords.color + 0x080000) \
// 					: (global->coords.color = global->coords.color - 0x080000);
// 	else if (key == 86 || key == 88)
// 		(key == 88) ? (global->coords.color = global->coords.color - 0x000800) \
// 					: (global->coords.color = global->coords.color + 0x000800);
// 	else if (key == 83 || key == 85)
// 		(key == 85) ? (global->coords.color = global->coords.color - 0x000008) \
// 					: (global->coords.color = global->coords.color + 0x000008);
// 	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
// 	launch_map(global);
// 	return (1);
// }
