/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:58:47 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/21 14:58:48 by iporsenn         ###   ########.fr       */
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
	c[0] = (x / global->fract[global->id].zoom_x + \
												global->fract[global->id].x1);
	c[1] = (y / global->fract[global->id].zoom_y + \
												global->fract[global->id].y1);
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
		z[0] = z[0] * z[0] - z[1] * z[1] + global->fract[global->id].c[0];
		z[1] = 2 * z[1] * tmp + global->fract[global->id].c[1];
		i++;
		color(global, x, y, i);
	}
	return (0);
}

int		tricorn(int x, int y, t_global *global)
{
	int			i;
	long double	z[2];
	long double c[2];
	long double	tmp;

	i = 0;
	c[0] = (x / global->fract[global->id].zoom_x + \
												global->fract[global->id].x1);
	c[1] = (y / global->fract[global->id].zoom_y + \
												global->fract[global->id].y1);
	z[0] = 0;
	z[1] = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = -2 * z[1] * tmp + c[1];
		i++;
	}
	color(global, x, y, i);
	return (0);
}

int		ship(int x, int y, t_global *global)
{
	int			i;
	long double	z[2];
	long double c[2];
	long double	tmp;

	i = 0;
	c[0] = (x / global->fract[global->id].zoom_x + \
												global->fract[global->id].x1);
	c[1] = (y / global->fract[global->id].zoom_y + \
												global->fract[global->id].y1);
	z[0] = 0;
	z[1] = 0;
	while ((z[0] * z[0] + z[1] * z[1] < 4) && i < global->iter_max)
	{
		tmp = fabsl(z[0] * z[0] - z[1] * z[1] + c[0]);
		z[1] = 2 * fabsl(z[0] * z[1]) + c[1];
		z[0] = tmp;
		i++;
	}
	color(global, x, y, i);
	return (0);
}
