/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:02:59 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/18 13:03:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_img(t_img *img)
{
	img->p_mlx = NULL;
	img->p_win = NULL;
	img->p_img = NULL;
	img->img_addr = NULL;
	img->size = 0;
	img->endian = 0;
}

// static void	init_mandel(t_global *global)
// {
// 	global->mandel.y1 = -1.3;
// 	global->mandel.y2 = 1.2;
// 	global->mandel.x1 = -2.1;
// 	global->mandel.x2 = 0.6;
// 	global->mandel.img_y = 0;
// 	global->mandel.img_x = 0;
// 	global->mandel.zoom_x = 0;
// 	global->mandel.zoom_y = 0;
// 	global->zoom = 300;
// 	global->iter_max = 50;
// }

static void	init_julia(t_global *global)
{
	global->julia.y1 = -1.2;
	global->julia.y2 = 1.2;
	global->julia.x1 = -1;
	global->julia.x2 = 1;
	global->julia.img_y = 0;
	global->julia.img_x = 0;
	global->julia.zoom_x = 0;
	global->julia.zoom_y = 0;
	global->zoom = 300;
	global->iter_max = 150;
}

static void init_tmp(t_global *global)
{
	global->tmp.iter_max = global->iter_max;
	global->tmp.zoom = global->zoom;
	global->tmp.y1 = global->mandel.y1;
	global->tmp.y2 = global->mandel.y2;
	global->tmp.x1 = global->mandel.x1;
	global->tmp.x2 = global->mandel.x2;
}

static void	init_color(t_color *color)
{
	color->turn = 0;
	color->color[0][0] = 0x000000;
	color->color[0][1] = 0xFD00FF;
	color->color[0][2] = 0xFFFFFF;
	color->color[1][0] = 0x000000;
	color->color[1][1] = 0x00f9ff;
	color->color[1][2] = 0xFFFFFF;
	color->color[2][0] = 0x000000;
	color->color[2][1] = 0xD3FFCE;
	color->color[2][2] = 0xFFFFFF;
}

void		init_global(t_global *global)
{
	int i;

	i = -1;
	global->name = NULL;
	global->function[0] = &close_map;
	global->function[1] = &move_up_and_down;
	global->function[2] = &move_right_and_left;
	global->function[3] = &init_map;
	global->function[4] = &iteration;
	global->function[5] = &switch_color;
	global->len_function = 6;
	global->mouse_func[0] = &pointed_zoom;
	global->len_mouse = 1;
	while (++i < THREAD)
		global->thread[i] = 0;
	init_img(&global->img);
	// init_mandel(global);
	init_julia(global);
	init_color(&global->color);
	init_tmp(global);
}
