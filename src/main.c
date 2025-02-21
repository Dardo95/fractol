/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:53:10 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/22 17:02:27 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int init_data(t_data *data)
{
	data->minRe = -2.0;
	data->maxRe = 1.0; 
	data->minIm = -1.2;
	data->maxIm = 1.2;
	data->maxIter = 60;

	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data->mlx)
	{
		ft_printf("ERROR: MLX init failed\n");
		return (0);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_printf("ERROR: MLX img failed\n");
		mlx_terminate(data->mlx);
		return (0);
	}
	return (1);
}

void cleanup(t_data *data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

static int choose_fractal(char **argv, t_data *data)
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        draw_mandelbrot(data);
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        ft_printf("hola\n");
        return (EXIT_SUCCESS);
    }
    else
    {
        ft_printf("Unrecognized fractal. Use 'mandelbrot' or 'julia'.\n");
        return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{

	t_data data;

	if (argc < 2)
    {
        ft_printf("Usage: ./fractol mandelbrot | julia [cRe cIm]\n");
        return (EXIT_FAILURE);
    }
	if (!init_data(&data))
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0))
	{
		ft_printf("ERROR: Failed to put image to window\n");
		cleanup(&data);
		return (EXIT_FAILURE);
	}
	choose_fractal(argv, &data);
	mlx_scroll_hook(data.mlx, handle_scroll, &data);
	mlx_key_hook(data.mlx, handle_keys, &data);
	mlx_loop(data.mlx);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
