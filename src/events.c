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

	// Redibujar el fractal
	draw_mandelbrot(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void handle_keys(mlx_key_data_t keydata, void *param)
{
    t_data *data = (t_data *)param;
    double move_step_x;
    double move_step_y;

    // Evitar advertencias de parámetros no usados (por ahora)
    (void)keydata;

    // Calculamos el paso de movimiento basado en el zoom actual
    move_step_x = (data->maxRe - data->minRe) * 0.1;  // 10% del ancho visible
    move_step_y = (data->maxIm - data->minIm) * 0.1;  // 10% del alto visible

    // Verificamos qué tecla se presionó
    if (keydata.action == MLX_PRESS)  // Solo cuando la tecla es presionada
    {
        if (keydata.key == MLX_KEY_LEFT)
        {
            data->minRe -= move_step_x;
            data->maxRe -= move_step_x;
        }
        else if (keydata.key == MLX_KEY_RIGHT)
        {
            data->minRe += move_step_x;
            data->maxRe += move_step_x;
        }
        else if (keydata.key == MLX_KEY_UP)
        {
            data->minIm += move_step_y;
            data->maxIm += move_step_y;
        }
        else if (keydata.key == MLX_KEY_DOWN)
        {
            data->minIm -= move_step_y;
            data->maxIm -= move_step_y;
        }

        // Redibujar el fractal después de cada movimiento
        draw_mandelbrot(data);
        mlx_image_to_window(data->mlx, data->img, 0, 0);
    }
}

