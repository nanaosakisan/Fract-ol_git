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
	int			i;

	i = 0;
	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") != 0 && ft_strcmp(av[1], \
		"julia") != 0 && ft_strcmp(av[1], "buh1") != 0 && ft_strcmp(av[1], \
		"buh2") != 0 && ft_strcmp(av[1], "buh3") != 0))
		error("usage: ./factol mandelbrot/julia");
	else
	{
		init_global(&global);
		while (ft_strcmp(av[1], global.fract[i].name) != 0)
			i++;
		global.name = global.fract[i].name;
		global.id = i;
		select_fract(&global);
		mlx_hook(global.img.p_win, 2, (1L << 0), deal_key, &global);
		mlx_mouse_hook(global.img.p_win, mouse_hook, &global);
		mlx_loop(global.img.p_mlx);
	}
	return(0);
}
