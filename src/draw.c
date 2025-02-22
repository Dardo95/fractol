/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:07:20 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/06 13:09:22 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static uint32_t	get_color(int i, int max_iter)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (i == max_iter)
		return (0x000000FF); // Negro para los puntos dentro del conjunto

	t = (double)i / max_iter;

	if (t < 0.5) // Primera mitad del gradiente: azul
	{
		r = (uint8_t)((1 - t) * 135 + t * 0);
		g = (uint8_t)((1 - t) * 206 + t * 30);
		b = (uint8_t)((1 - t) * 250 + t * 139);
	}
	else // Segunda mitad del gradiente: amarillo
	{
		r = (uint8_t)((t - 0.5) * 2 * 255); // Rojo sube
		g = (uint8_t)((t - 0.5) * 2 * 255); // Verde sube
		b = 0; // Azul desaparece
	}

	return ((r << 24) | (g << 16) | (b << 8) | 0xFF); // Formato RGBA
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

void	draw_mandelbrot(t_data *data, t_complex *comp)
{
	int			y;
	int			x;
	int			i;
	uint32_t	color;

	color = 0xFFF00FFF;
	y = 0;
	data->scale_re = (data->max_re - data->min_re) / WIDTH;
	data->scale_im = (data->max_im - data->min_im) / HEIGHT;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			comp->c_re = data->min_re + x * data->scale_re;
			comp->c_im = data->max_im - y * data->scale_im;
			i = mandelbrot_iterations(comp, data->max_iter);
			color = get_color(i, data->max_iter);
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}
