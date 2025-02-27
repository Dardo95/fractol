/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:22:04 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/26 23:02:20 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>

# define WIDTH 1300
# define HEIGHT 900

typedef struct s_complex
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
}			t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		min_re;
	double		max_re;
	double		min_im;
	double		hue;
	double		max_im;
	double		scale_re;
	double		scale_im;
	int			max_iter;
	int			fractal_type;
	t_complex	mand_c;
	double		j_c_r;
	double		j_c_i;
}				t_data;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;	
	double	*p;
	double	*q;
	double	*t;
}			t_hsv;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}			t_rgb;

void		draw_mandelbrot(t_data *data);
void		draw_julia(t_data *data);
int			set_julia_params(char **argv, t_data *data);
void		handle_scroll(double xoffset, double yoffset, void *param);
void		handle_keys(mlx_key_data_t keydata, void *param);
void		cleanup(t_data *data);
int			valid_doble(char *param);

//     Colors      //

void		hsv2rgb_calc_intermediate(t_hsv hsv_t);
void		hsv_fill_rgb(t_rgb *rgb_t, double hsv1, double hsv2, double hsv3);
void		hsv2rgb_handle_saturation(t_rgb *rgb_t, t_hsv hsv_t);
int			hsv2rgb_adjust_rgb(t_rgb rgb_t);
int			hsv2rgb(double h, double s, double v);

#endif
