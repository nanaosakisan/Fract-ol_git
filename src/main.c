/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:55:00 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/11 14:55:01 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_global	global;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") != 0 && ft_strcmp(av[1], \
		"julia") != 0 && ft_strcmp(av[1], "buh1") != 0 && ft_strcmp(av[1], \
		"buh2") != 0 && ft_strcmp(av[1], "buh3") != 0))
		error("usage: ./factol mandelbrot/julia");
	else
	{
		init_global(&global);
		global.name = av[1];
		global.img.p_mlx = mlx_init();
		global.img.p_win = mlx_new_window(global.img.p_mlx, WIDTH, HEIGHT, \
															global.name);
		mandelbrot(&global);
		mlx_hook(global.img.p_win, 2, (1L << 0), deal_key, &global);
		mlx_loop(global.img.p_mlx);
	}
	return(0);
}
