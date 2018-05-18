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

static void	init_mandel(t_global *global)
{
	global->fract[0].name = "mandelbrot";
	global->fract[0].y1 = -1.3;
	global->fract[0].y2 = 1.2;
	global->fract[0].x1 = -2.1;
	global->fract[0].x2 = 0.6;
	global->fract[0].img_y = 0;
	global->fract[0].img_x = 0;
	global->fract[0].zoom_x = 0;
	global->fract[0].zoom_y = 0;
}

static void	init_julia(t_global *global)
{
	global->fract[1].name = "julia";
	global->fract[1].y1 = -1.3;
	global->fract[1].y2 = 1.7;
	global->fract[1].x1 = -1.4;
	global->fract[1].x2 = 1.3;
	global->fract[1].img_y = 0;
	global->fract[1].img_x = 0;
	global->fract[1].zoom_x = 0;
	global->fract[1].zoom_y = 0;
}

static void	init_tricorn(t_global *global)
{
	global->fract[2].name = "tricorn";
	global->fract[2].y1 = -1.3;
	global->fract[2].y2 = 1.5;
	global->fract[2].x1 = -2;
	global->fract[2].x2 = 1;
	global->fract[2].img_y = 0;
	global->fract[2].img_x = 0;
	global->fract[2].zoom_x = 0;
	global->fract[2].zoom_y = 0;
}

static void	init_buddha(t_global *global)
{
	global->fract[3].name = "buddhabrot";
	global->fract[0].y1 = -1.3;
	global->fract[0].y2 = 1.2;
	global->fract[0].x1 = -2.1;
	global->fract[0].x2 = 0.6;
	global->fract[0].img_y = 0;
	global->fract[0].img_x = 0;
	global->fract[0].zoom_x = 0;
	global->fract[0].zoom_y = 0;
}

void 		init_tmp(t_global *global)
{
	global->tmp.iter_max = global->iter_max;
	global->tmp.zoom = global->zoom;
	global->tmp.y1 = global->fract[global->id].y1;
	global->tmp.y2 = global->fract[global->id].y2;
	global->tmp.x1 = global->fract[global->id].x1;
	global->tmp.x2 = global->fract[global->id].x2;
}

static void	init_color(t_color *color)
{
	color->turn = 0;
	color->color[0][0] = 0x000000;
	color->color[0][1] = 0xFD00FF;
	color->color[0][2] = 0xFE7FFF;
	color->color[0][3] = 0xFFFFFF;
	color->color[1][0] = 0x000000;
	color->color[1][1] = 0x00F9FF;
	color->color[1][2] = 0x7FFCFF;
	color->color[1][3] = 0xFFFFFF;
	color->color[2][0] = 0x000000;
	color->color[2][1] = 0xD3FFCE;
	color->color[2][2] = 0xE9FFE6;
	color->color[2][3] = 0xFFFFFF;
}

void		init_global(t_global *global)
{
	int i;

	i = -1;
	global->name = NULL;
	global->id = 0;
	global->function[0] = &mandel;
	global->function[1] = &julia;
	global->function[2] = &tricorn;
	global->function[3] = &buddha;
	global->key_func[0] = &close_map;
	global->key_func[1] = &move_up_and_down;
	global->key_func[2] = &move_right_and_left;
	global->key_func[3] = &init_map;
	global->key_func[4] = &iteration;
	global->key_func[5] = &switch_color;
	global->len_key = 6;
	global->mouse_func[0] = &pointed_zoom;
	global->len_mouse = 1;
	global->zoom = 300;
	global->iter_max = 200;
	global->iter_min = 50;
	while (++i < THREAD)
		global->thread[i] = 0;
	init_img(&global->img);
	init_mandel(global);
	init_julia(global);
	init_tricorn(global);
	init_buddha(global);
	init_color(&global->color);
}
