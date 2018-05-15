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

# define HEIGHT 800
# define WIDTH 800
# define THREAD 1
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

typedef struct	s_fract
{
	char			*name;
	long double		y1;
	long double		y2;
	long double		x1;
	long double		x2;
	long double		img_x;
	long double		img_y;
	long double		zoom_x;
	long double		zoom_y;
}				t_fract;

typedef struct	s_tmp
{
	int 		iter_max;
	int 		zoom;
	long double	y1;
	long double	y2;
	long double	x1;
	long double	x2;
}				t_tmp;

typedef	struct	s_color
{
	int		color[3][3];
	int		turn;
}				t_color;

typedef struct	s_global
{
	char			*name;
	int				index;
	t_img			img;
	struct s_fract	fract[2];
	t_tmp			tmp;
	t_color			color;
	int				(*function[6]) (struct s_global*, int);
	int				(*mouse_func[1]) (int, int, int, struct s_global*);
	int				len_function;
	int				len_mouse;
	long double		zoom;
	int				iter_max;
	pthread_t		thread[THREAD];
}				t_global;

int			close_map(t_global *global, int key);
void		color(t_global *global, int x, int y, int i);
int			deal_key(int key, t_global *global);
void		draw_segment(float *coord_src, float *coord_dst, t_global *global);
void		init_global(t_global *global);
int			init_map(t_global *global, int key);
int			iteration(t_global *global, int key);
int			launch_draw(t_global *global);
int			launch_draw_julia(t_global *global);
int			main(int ac, char **av);
int			mouse_hook(int key, int x, int y, t_global *global);
int			move_right_and_left(t_global *global, int key);
int			move_up_and_down(t_global *global, int key);
int			pointed_zoom(int key, int x, int y, t_global *global);
int			switch_color(t_global *global, int key);
int			zoom(t_global *global, int key);

# endif
