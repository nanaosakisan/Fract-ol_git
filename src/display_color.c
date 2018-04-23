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

int		display_color(t_global *global, int i)
{
	int		color1 = 0x800080;
	int		color2 = 0xFFFFFF;
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	r2;
	unsigned char	b2;
	unsigned char	g2;

	if (!global)
		return(0);
	r1 = (color1 >> 16);
	g1 = ((color1 >> 8) & 0xFF);
	b1 = ((color1) & 0xFF);
	r2 = (color2 >> 16);
	g2 = ((color2 >> 8) & 0xFF);
	b2 = ((color2) & 0xFF);
	r2 = r1 + ((r2 - r1) / global->iter_max) * i;
	g2 = g1 + ((g2 - g1) / global->iter_max) * i;
	b2 = b1 + ((b2 - b1) / global->iter_max) * i;
	color1 |= r2 << 16;
	color1 |= g2 << 8;
	color1 |= b2;
	return (color1);
}
