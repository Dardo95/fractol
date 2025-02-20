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

static uint32_t get_color(int i, int maxIter)
{
	double t;
    uint8_t r;
	uint8_t g;
	uint8_t b;

    if (i == maxIter)
        return 0x0A0F30FF;

    t = (double)i / maxIter;
    r = (uint8_t)((1 - t) * 135 + t * 0);
    g = (uint8_t)((1 - t) * 206 + t * 30);
    b = (uint8_t)((1 - t) * 250 + t * 139);

    return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

static int	mandelbrot_iterations(double cRe, double cIm, int maxIter)
{
	double	zRe;
	double	zIm;
	int		i;
	double	tmp;

	zRe = 0.0;
	zIm = 0.0;
	i = 0;
	while ((zRe * zRe + zIm * zIm <= 4.0) && (i < maxIter))
	{
		tmp = (zRe * zRe) - (zIm * zIm) + cRe;
		zIm = 2.0 * zRe * zIm + cIm;
		zRe = tmp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_data *data)
{
	int			y;
	int			x;
	double		cRe;
	double		cIm;
	int			i;
	double		scaleRe;
	double		scaleIm;
	uint32_t	color;

	color = 0xFFF00FFF;
	y = 0;
	scaleRe = (data->maxRe - data->minRe) / WIDTH;
	scaleIm = (data->maxIm - data->minIm) / HEIGHT;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cRe = data->minRe + x * scaleRe;
			cIm = data->maxIm - y * scaleIm;
			i = mandelbrot_iterations(cRe, cIm, data->maxIter);
			color = get_color(i, data->maxIter);
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

