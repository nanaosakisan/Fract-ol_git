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

// void	third_ui(t_global *global)
// {
// 	mlx_string_put(global->img.p_mlx, global->img.p_win, 610, 280, 0xFFFFFF, \
// 															"PALETTE NUMERO");
// 	mlx_string_put(global->img.p_mlx, global->img.p_win, 960, 280, 0xFFFFFF, \
// 															":");
// 	mlx_string_put(global->img.p_mlx, global->img.p_win, 980, 280, 0xFFFFFF, \
// 												ft_itoa(global->color.turn));
// }

static void	second_ui(t_global *global)
{
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 130, 0xFFFFFF, \
											"AUGMENTER/DIMINUER ITERATIONS");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 130, 0xFFFFFF, \
															": PAGE UP/DOWN");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 160, 0xFFFFFF, \
												"CHANGER COULEUR");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 160, 0xFFFFFF, \
																": CONTROL");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 190, 0xFFFFFF, \
													"CHANGER FRACTAL ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 190, 0xFFFFFF, \
													": BOUTON COTE SOURIS ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 220, 0xFFFFFF, \
										"ACTIVER CHANGEMENT PARAMETRE JULIA ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 220, 0xFFFFFF, \
																	": SHIFT ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 250, 0xFFFFFF, \
												"CHANGER PARAMETRES JULIA ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 250, 0xFFFFFF, \
													": DEPLACEMENT SOURIS ");
	// third_ui(global);
}

void		first_ui(t_global *global)
{
	global->bonus.p_img = mlx_new_image(global->img.p_mlx, WIDTH_UI, \
																HEIGHT);
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 10, 0xFFFFFF, \
																	"QUITTER ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 10, 0xFFFFFF, \
																	": ECHAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 40, 0xFFFFFF, \
														"REINITIALISER MAP");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 40, 0xFFFFFF, \
																	": 0");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 70, 0xFFFFFF, \
																"ZOOM/DEZOOM ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 70, 0xFFFFFF, \
													": CLICS SOURIS/MOLETTE");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 510, 100, 0xFFFFFF, \
															"DEPLACER MAP ");
	mlx_string_put(global->img.p_mlx, global->img.p_win, 860, 100, 0xFFFFFF, \
																": FLECHES");
	second_ui(global);
	mlx_put_image_to_window(global->img.p_mlx, global->img.p_win, \
										global->bonus.p_img, 0, WIDTH);
}
