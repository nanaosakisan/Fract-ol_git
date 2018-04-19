/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:55:13 by iporsenn          #+#    #+#             */
/*   Updated: 2018/04/11 14:55:15 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
# define	FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>

# define HEIGHT	1000
# define WIDTH	1000
# define I_MAX	50
# define ZOOM	100

typedef	struct	s_img
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
}				t_img;

typedef struct	s_global
{
	char 	*name;
	t_img	img;
	int		(*function[1]) (struct s_global*, int);
	int		len_array;
}				t_global;

int			close_map(t_global *global, int key);
int			deal_key(int key, t_global *global);
void		draw_segment(float *coord_src, float *coord_dst, t_global *global);
void		init_global(t_global *global);
int			main(int ac, char **av);
int			mandelbrot(t_global *global);
void		mlx_pixel_put_to_image(t_global *dna, int x, int y, int color);
# endif
