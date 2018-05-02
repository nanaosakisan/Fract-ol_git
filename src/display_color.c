/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:06 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/20 16:52:13 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	display_color(t_global *global, int i, int color1, int color2)
{
	int				color;
	unsigned char	tab1[3];
	unsigned char	tab2[3];

	color = 0;
	tab1[0] = (color1 >> 16);
	tab1[1] = ((color1 >> 8) & 0xFF);
	tab1[2] = ((color1) & 0xFF);
	tab2[0] = (color2 >> 16);
	tab2[1] = ((color2 >> 8) & 0xFF);
	tab2[2] = ((color2) & 0xFF);
	tab2[0] = tab1[0] + ((tab2[0] - tab1[0]) / global->iter_max) * i;
	tab2[1] = tab1[1] + ((tab2[1] - tab1[1]) / global->iter_max) * i;
	tab2[2] = tab1[2] + ((tab2[2] - tab1[2]) / global->iter_max) * i;
	color |= tab2[0] << 16;
	color |= tab2[1] << 8;
	color |= tab2[2];
	return (color);
}

void		color(t_global *global, int x, int y, int i)
{
	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x, y, 0x000000);
	else if (i < global->iter_max / 2 - 1)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][0], \
								global->color.color[global->color.turn][1]));
	else if (i > global->iter_max / 2 && i < global->iter_max - 1)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][1], \
								global->color.color[global->color.turn][2]));
}
