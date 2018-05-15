/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:28:40 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/15 14:28:43 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		select_fract(t_global *global)
{
	global.img.p_mlx = mlx_init();
	global.img.p_win = mlx_new_window(global.img.p_mlx, WIDTH, HEIGHT, \
														global.name);
	lauch_fractal // fonction de la fractal dans tableau de pointeur sur fonction
				 // vers toutes les fonctions de fractale
	mlx_hook(global.img.p_win, 2, (1L << 0), deal_key, &global);
	mlx_mouse_hook(global.img.p_win, mouse_hook, &global);
	mlx_loop(global.img.p_mlx);
	return (0);
}
