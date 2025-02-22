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

static void	update_fractal(t_data *data, t_complex *comp)
{
	draw_mandelbrot(data, comp);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	handle_scroll(double xoffset, double yoffset, void *param)
{
	t_data		*data;
	int32_t		mouse_x;
	int32_t		mouse_y;
	t_complex	comp;
	double		zoom_factor;

	data = (t_data *)param;
	(void)xoffset;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	comp.c_re = data->min_re + (mouse_x / (double)WIDTH)
		* (data->max_re - data->min_re);
	comp.c_im = data->max_im - (mouse_y / (double)HEIGHT)
		* (data->max_im - data->min_im);
	if (yoffset > 0)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	data->min_re = comp.c_re + (data->min_re - comp.c_re) * zoom_factor;
	data->max_re = comp.c_re + (data->max_re - comp.c_re) * zoom_factor;
	data->min_im = comp.c_im + (data->min_im - comp.c_im) * zoom_factor;
	data->max_im = comp.c_im + (data->max_im - comp.c_im) * zoom_factor;
	update_fractal(data, &comp);
}

void	move_view(t_data *data, mlx_key_data_t keydata)
{
	double	move_step;

	move_step = (data->max_re - data->min_re) * 0.1;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
	{
		if (keydata.key == MLX_KEY_LEFT)
			move_step = -move_step;
		data->min_re += move_step;
		data->max_re += move_step;
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		if (keydata.key == MLX_KEY_DOWN)
			move_step = -move_step;
		data->min_im += move_step;
		data->max_im += move_step;
	}
}

void	handle_exit(t_data *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		cleanup(data);
		exit(EXIT_SUCCESS);
	}
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_data		*data;
	t_complex	comp ;

	data = (t_data *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	handle_exit(data, keydata);
	move_view(data, keydata);
	update_fractal(data, &comp);
}

