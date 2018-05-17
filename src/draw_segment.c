/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:47:45 by iporsenn          #+#    #+#             */
/*   Updated: 2018/03/28 18:54:00 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		draw_horizon(float *coord, int *diff, int *inc, \
															t_global *global)
{
	int		i;
	int		cumul;
	float	x1;

	x1 = coord[1];
	cumul = diff[1] / 2;
	i = -1;
	while (++i < diff[1])
	{
		x1 += inc[1];
		cumul += diff[0];
		if (cumul >= diff[1])
		{
			cumul -= diff[1];
			coord[0] += inc[0];
		}
		if ((x1 > 0 && x1 < WIDTH) && (coord[0] > 0 && coord[0] < HEIGHT))
			mlx_pixel_put_to_image(global, x1, coord[0], 0xFFFFFF);
	}
}

static void		draw_vertical(float *coord, int *diff, int *inc, \
															t_global *global)
{
	int i;
	int cumul;

	cumul = diff[0] / 2;
	i = -1;
	while (++i < diff[0])
	{
		coord[0] += inc[0];
		cumul += diff[1];
		if (cumul >= diff[0])
		{
			cumul -= diff[0];
			coord[1] += inc[1];
		}
		if ((coord[1] > 0 && coord[1] < WIDTH) && (coord[0] > 0 && coord[0] < \
																		HEIGHT))
			mlx_pixel_put_to_image(global, coord[1], coord[0], 0xFFFFFF);
	}
}

void			draw_segment(float *coord_src, float *coord_dst, \
															t_global *global)
{
	int diff[2];
	int inc[2];

	diff[0] = coord_dst[0] - coord_src[0];
	diff[1] = coord_dst[1] - coord_src[1];
	inc[0] = (diff[0] > 0) ? 1 : -1;
	inc[1] = (diff[1] > 0) ? 1 : -1;
	diff[0] = abs(diff[0]);
	diff[1] = abs(diff[1]);
	if ((coord_src[1] > 0 && coord_src[1] < WIDTH) && (coord_src[0] > 0 && \
														coord_src[0] < HEIGHT))
		mlx_pixel_put_to_image(global, coord_src[1], coord_src[0], 0xFFFFFF);
	if (diff[1] > diff[0])
		draw_horizon(coord_src, diff, inc, global);
	else
		draw_vertical(coord_src, diff, inc, global);
}
