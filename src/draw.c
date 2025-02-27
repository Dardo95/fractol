/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:07:20 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/26 21:33:29 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static uint32_t	get_hsv_color(t_data *data, int i)
{
	double	hue;
	double	sat;
	double	val;

	if (i == data->max_iter)
		return (0xFF000000);
	hue = ((double)i * 360.0) / data->max_iter;
	hue = fmod(hue + pow(data->fractal_type, 1.5), 360.0);
	sat = 100.0;
	val = ((double)i / data->max_iter) * 100.0;
	return (hsv2rgb(hue, sat, val));
}

static int	mandelbrot_iterations(t_complex *comp, int max_iter)
{
	double	z_re;
	double	z_im;
	int		i;
	double	tmp;

	z_re = 0.0;
	z_im = 0.0;
	i = 0;
	while ((z_re * z_re + z_im * z_im <= 4.0) && (i < max_iter))
	{
		tmp = (z_re * z_re) - (z_im * z_im) + comp->c_re;
		z_im = 2.0 * z_re * z_im + comp->c_im;
		z_re = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_data *data)
{
	int			y;
	int			x;
	int			i;
	uint32_t	color;

	y = 0;
	data->scale_re = (data->max_re - data->min_re) / WIDTH;
	data->scale_im = (data->max_im - data->min_im) / HEIGHT;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->mand_c.z_re = 0.0;
			data->mand_c.z_im = 0.0;
			data->mand_c.c_re = data->min_re + x * data->scale_re;
			data->mand_c.c_im = data->max_im - y * data->scale_im;
			i = mandelbrot_iterations(&data->mand_c, data->max_iter);
			color = get_hsv_color(data, i);
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

static int	julia_iterations(t_complex *comp, int max_iter)
{
	int		i;
	double	tmp;

	i = 0;
	while ((comp->z_re * comp->z_re + comp->z_im
			* comp->z_im <= 4.0) && (i < max_iter))
	{
		tmp = (comp->z_re * comp->z_re)
			- (comp->z_im * comp->z_im) + comp->c_re;
		comp->z_im = 2.0 * comp->z_re * comp->z_im + comp->c_im;
		comp->z_re = tmp;
		i++;
	}
	return (i);
}

void	draw_julia(t_data *data)
{
	int			y;
	int			x;
	int			i;
	uint32_t	color;
	t_complex	pixel;

	y = 0;
	data->scale_re = (data->max_re - data->min_re) / WIDTH;
	data->scale_im = (data->max_im - data->min_im) / HEIGHT;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel.z_re = data->min_re + x * data->scale_re;
			pixel.z_im = data->max_im - y * data->scale_im;
			pixel.c_re = data->j_c_r;
			pixel.c_im = data->j_c_i;
			i = julia_iterations(&pixel, data->max_iter);
			color = get_hsv_color(data, i);
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}
