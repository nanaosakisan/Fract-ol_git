/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:59:25 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/21 14:59:30 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_ship(t_global *global)
{
	global->fract[3].name = "burning_ship";
	global->fract[3].y1 = -2;
	global->fract[3].y2 = 1;
	global->fract[3].x1 = -1.6;
	global->fract[3].x2 = 1.3;
	global->fract[3].img_y = 0;
	global->fract[3].img_x = 0;
	global->fract[3].zoom_x = 0;
	global->fract[3].zoom_y = 0;
}

static void	init_tricorn(t_global *global)
{
	global->fract[2].name = "tricorn";
	global->fract[2].y1 = -1.3;
	global->fract[2].y2 = 1.5;
	global->fract[2].x1 = -1.7;
	global->fract[2].x2 = 1.5;
	global->fract[2].img_y = 0;
	global->fract[2].img_x = 0;
	global->fract[2].zoom_x = 0;
	global->fract[2].zoom_y = 0;
	init_ship(global);
}

static void	init_julia(t_global *global)
{
	global->fract[1].name = "julia";
	global->fract[1].turn = 0;
	global->fract[1].y1 = -1.3;
	global->fract[1].y2 = 4;
	global->fract[1].x1 = -1.4;
	global->fract[1].x2 = 2;
	global->fract[1].img_y = 0;
	global->fract[1].img_x = 0;
	global->fract[1].zoom_x = 0;
	global->fract[1].zoom_y = 0;
	global->fract[1].c[0] = -0.7269;
	global->fract[1].c[1] = 0.1889;
	init_tricorn(global);
}

void		init_mandel(t_global *global)
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
	init_julia(global);
}
