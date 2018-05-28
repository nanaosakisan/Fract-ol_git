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

void		init_tmp(t_global *global)
{
	if (global->id == 0)
		global->iter_max = 100;
	else if (global->id == 1)
		global->iter_max = 150;
	else if (global->id == 2)
		global->iter_max = 30;
	else if (global->id == 3)
		global->iter_max = 30;
	global->tmp.iter_max = global->iter_max;
	global->tmp.zoom = global->zoom;
	global->tmp.y1 = global->fract[global->id].y1;
	global->tmp.y2 = global->fract[global->id].y2;
	global->tmp.x1 = global->fract[global->id].x1;
	global->tmp.x2 = global->fract[global->id].x2;
}

static void	init_bonus(t_bonus *bonus)
{
	bonus->p_img = NULL;
	bonus->img_addr = NULL;
	bonus->size = 0;
	bonus->endian = 0;
}

static void	init_color(t_global *global)
{
	global->color.turn = 0;
	global->color.color[0][0] = 0x000000;
	global->color.color[0][1] = 0xFD00FF;
	global->color.color[0][2] = 0x301637;
	global->color.color[0][3] = 0xFFFFFF;
	global->color.color[1][0] = 0x000000;
	global->color.color[1][1] = 0x00F9FF;
	global->color.color[1][2] = 0x003133;
	global->color.color[1][3] = 0xFFFFFF;
	global->color.color[2][0] = 0x000000;
	global->color.color[2][1] = 0xE50000;
	global->color.color[2][2] = 0x440000;
	global->color.color[2][3] = 0xFFFFFF;
	init_bonus(&global->bonus);
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
	global->function[3] = &ship;
	global->key_func[0] = &close_map;
	global->key_func[1] = &move_up_and_down;
	global->key_func[2] = &move_right_and_left;
	global->key_func[3] = &init_map;
	global->key_func[4] = &iteration;
	global->key_func[5] = &switch_color;
	global->len_key = 6;
	global->mouse_func[0] = &pointed_zoom;
	global->mouse_func[1] = &turn_julia;
	global->mouse_func[2] = &turn_fract;
	global->len_mouse = 3;
	global->zoom = 230;
	while (++i < THREAD)
		global->thread[i] = 0;
	init_img(&global->img);
	init_mandel(global);
	init_color(global);
}
