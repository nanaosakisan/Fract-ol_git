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
	global->mandel.y1 = -1.2;
	global->mandel.y2 = 1.2;
	global->mandel.x1 = -2.1;
	global->mandel.x2 = 0.6;
	global->mandel.img_y = 0;
	global->mandel.img_x = 0;
	global->mandel.zoom_x = 0;
	global->mandel.zoom_y = 0;
	global->mandel.c_r = 0;
	global->mandel.c_i = 0;
	global->zoom = 100;
	global->iter_max = 50;
}

void		init_global(t_global *global)
{
	global->name = NULL;
	global->function[0] = &close_map;
	global->function[1] = &zoom;
	global->function[2] = &move_up_and_down;
	global->function[3] = &move_right_and_left;
	global->function[4] = &init_map;
	global->function[5] = &iteration;
	global->len_array = 6;
	global->pos[0] = 0;
	global->pos[1] = 0;
	global->move[0] = 0;
	global->move[1] = 0;
	global->color1 = 0x800080;
	global->color2 = 0xFFFFFF;
	init_img(&global->img);
	init_mandel(global);
}
