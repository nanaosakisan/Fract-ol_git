/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:15:13 by iporsenn          #+#    #+#             */
/*   Updated: 2018/05/21 14:15:15 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	right_ui(t_global *global)
{
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 730, 0xFFFFFF, \
											"AUGMENTER/DIMINUER ITERATIONS");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 730, 0xFFFFFF, \
															": PAGE UP/DOWN");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 760, 0xFFFFFF, \
												"CHANGER COULEUR");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 760, 0xFFFFFF, \
																": CONTROL");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 790, 0xFFFFFF, \
													"CHANGER FRACTAL ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 790, 0xFFFFFF, \
													": BOUTON COTE SOURIS ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 820, 0xFFFFFF, \
													"CHANGER PARAMETRE JULIA ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 820, 0xFFFFFF, \
													": MOLETTE SOURIS ");

}

void		left_ui(t_global *global)
{
	global->bonus.p_img = mlx_new_image(global->img.p_mlx, WIDTH, \
																HEIGHT_UI);
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 610, 0xFFFFFF, \
																	"QUITTER ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 610, 0xFFFFFF, \
																	": ECHAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 640, 0xFFFFFF, \
														"REINITIALISER MAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 640, 0xFFFFFF, \
																	": 0");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 670, 0xFFFFFF, \
																"ZOOM/DEZOOM ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 670, 0xFFFFFF, \
															": CLICS SOURIS");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 10, 700, 0xFFFFFF, \
															"DEPLACER MAP ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 310, 700, 0xFFFFFF, \
												": FLECHES DIRECTIONNELLES");
	right_ui(global);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
										global->bonus.p_img, HEIGHT, 0);
}
