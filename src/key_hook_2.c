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

int		iteration(t_global *global, int key)
{
	if (key != 116 && key != 121)
		return (0);
	else if (key == 116)
		global->iter_max += 1;
	else if (key == 121)
	{
		if (global->iter_max > 2)
			global->iter_max -= 1;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		switch_color(t_global *global, int key)
{
	if (key != 256)
		return (0);
	else
	{
		if (global->color.turn == 2)
			global->color.turn = 0;
		else
			global->color.turn += 1;
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}

int		activate_mouse_position(t_global *global, int key)
{
	if (key != 257)
		return (0);
	else
	{
		if (global->id == 1)
			global->fract[1].turn += (global->fract[1].turn == 0) ? 1 : -1;
		else
			return (0);
	}
	mlx_destroy_image(global->img.p_mlx, global->img.p_img);
	select_fract(global);
	return (1);
}
