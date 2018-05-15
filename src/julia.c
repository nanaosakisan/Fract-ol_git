/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:06:49 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/14 15:06:51 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		julia(int x, int y, t_global *global)
{
	long double z[2];
	long double tmp;
	int			i;

	z[0] = x / global->fract[global->id].zoom_x + global->fract[global->id].x1;
	z[1] = y / global->fract[global->id].zoom_y + global->fract[global->id].y1;
	i = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + 0.285;
		z[1] = 2 * z[1] * tmp + 0.01;
		i++;
		if (i == global->iter_max)
			mlx_pixel_put_to_image(global, x, y, 0x4DCD32);
		else
			mlx_pixel_put_to_image(global, x, y, 0x000000);
	}
	return (0);
}
