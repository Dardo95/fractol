/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:07:20 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/22 17:19:31 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_mandelbrot(t_data *data)
{
	int		y;
	int		x;
	double	cRe;
	double	cIm;
	int		i;
	uint32_t color;

	color = 0xFFF00FFF;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cRe = data->minRe + (x / (double)WIDTH) * (data->maxRe
					- data->minRe);
			cIm = data->maxIm - (y / (double)HEIGHT) * (data->maxIm
					- data->minIm);
			i = mandelbrot_iterations(cRe, cIm, data->maxIter);

			
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

int mandelbrot_iterations(double cRe, double cIm, int maxIter)
{
    double zRe = 0.0;
    double zIm = 0.0;
    int    i = 0;

    while ((zRe * zRe + zIm * zIm <= 4.0) && (i < maxIter))
    {
        double tmp = (zRe * zRe) - (zIm * zIm) + cRe;
        zIm = 2.0 * zRe * zIm + cIm;
        zRe = tmp;
        i++;
    }
    return (i);
}
