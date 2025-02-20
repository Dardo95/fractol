/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:53:10 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/22 17:02:27 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void update_fractal(t_data *data)
{
	draw_mandelbrot(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	handle_scroll(double xoffset, double yoffset, void *param)
{
	t_data *data = (t_data *)param;
	int32_t mouse_x, mouse_y;
	double cRe, cIm;
	double zoom_factor;

	(void)xoffset;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	cRe = data->minRe + (mouse_x / (double)WIDTH) * (data->maxRe - data->minRe);
	cIm = data->maxIm - (mouse_y / (double)HEIGHT) * (data->maxIm - data->minIm);
	if (yoffset > 0)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	data->minRe = cRe + (data->minRe - cRe) * zoom_factor;
	data->maxRe = cRe + (data->maxRe - cRe) * zoom_factor;
	data->minIm = cIm + (data->minIm - cIm) * zoom_factor;
	data->maxIm = cIm + (data->maxIm - cIm) * zoom_factor;
	update_fractal(data);
}

void handle_keys(mlx_key_data_t keydata, void *param)
{
    t_data *data;
    double move_step;

	data = (t_data *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	move_step = (data->maxRe - data->minRe) * 0.1;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
	{
		if (keydata.key == MLX_KEY_LEFT)
			move_step = -move_step;
		data->minRe += move_step;
		data->maxRe += move_step;
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		if (keydata.key == MLX_KEY_DOWN)
			move_step = -move_step;
		data->minIm += move_step;
		data->maxIm += move_step;
	}
	else
		return ;
	update_fractal(data);
}

