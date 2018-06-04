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
	unsigned int	color;
	unsigned char	tab_1[3];
	unsigned char	tab_2[3];

	color = 0;
	tab_1[0] = (color1 >> 16);
	tab_1[1] = ((color1 >> 8) & 0xFF);
	tab_1[2] = ((color1) & 0xFF);
	tab_2[0] = (color2 >> 16);
	tab_2[1] = ((color2 >> 8) & 0xFF);
	tab_2[2] = ((color2) & 0xFF);
	tab_2[0] = tab_1[0] + ((tab_2[0] - tab_1[0]) / (global->iter_max / 2)) * i;
	tab_2[1] = tab_1[1] + ((tab_2[1] - tab_1[1]) / (global->iter_max / 2)) * i;
	tab_2[2] = tab_1[2] + ((tab_2[2] - tab_1[2]) / (global->iter_max / 2)) * i;
	color |= tab_2[0] << 16;
	color |= tab_2[1] << 8;
	color |= tab_2[2];
	return (color);
}

static void	color_mandel(t_global *global, int x, int y, int i)
{
	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x, y, 0x000000);
	else if (i >= global->iter_max / 2 && i <= global->iter_max - 1)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][2], \
								global->color.color[global->color.turn][3]));
	else if (i < global->iter_max / 2)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][1], \
								global->color.color[global->color.turn][2]));
}

static void	color_julia(t_global *global, int x, int y, int i)
{
	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x, y, 0x000000);
	else if (i >= global->iter_max / 2 && i <= global->iter_max - 1)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][2], \
								global->color.color[global->color.turn][3]));
	else if (i < global->iter_max / 2)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][1], \
								global->color.color[global->color.turn][2]));
}

static void	color_ship(t_global *global, int x, int y, int i)
{
	if (i == global->iter_max)
		mlx_pixel_put_to_image(global, x, y, 0x000000);
	else if (i < global->iter_max / 2)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][2], \
								global->color.color[global->color.turn][1]));
	else if (i >= global->iter_max / 2 && i <= global->iter_max - 1)
		mlx_pixel_put_to_image(global, x, y, display_color(global, i, \
								global->color.color[global->color.turn][2], \
								global->color.color[global->color.turn][1]));
	else
		mlx_pixel_put_to_image(global, x, y, 0x00F9FF * i);
}

void		color(t_global *global, int x, int y, int i)
{
	if (global->id == 0 || global->id == 2)
		color_mandel(global, x, y, i);
	else if (global->id == 1)
		color_julia(global, x, y, i);
	else if (global->id == 3)
		color_ship(global, x, y, i);
}
