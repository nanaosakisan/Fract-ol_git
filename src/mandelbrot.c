/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract[global->id]brot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:22:56 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/13 15:23:02 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandel(int x, int y, t_global *global)
{
	int			i;
	long double	z[2];
	long double c[2];
	long double	tmp;

	i = 0;
	c[0] = (x / global->fract[global->id].zoom_x + global->fract[global->id].x1);
	c[1] = (y / global->fract[global->id].zoom_y + global->fract[global->id].y1);
	z[0] = 0;
	z[1] = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp - c[1];
		i++;
	}
	color(global, x, y, i);
	return (0);
}
