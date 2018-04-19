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

static void	init_img(t_global *global)
{
	global->img.p_mlx = NULL;
	global->img.p_win = NULL;
	global->img.p_img = NULL;
	global->img.img_addr = NULL;
	global->img.bpp = 0;
	global->img.size = 0;
	global->img.endian = 0;
}

void	init_global(t_global *global)
{
	global->name = NULL;
	global->function[0] = &close_map;
	global->len_array = 1;
	init_img(global);
}
