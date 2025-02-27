/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:53:10 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/26 23:10:38 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	set_fractal_limits(t_data *data, char *fractal_type)
{
	if (ft_strncmp(fractal_type, "mandelbrot", 11) == 0)
	{
		data->min_re = -2.0;
		data->max_re = 1.0;
		data->min_im = -1.2;
		data->max_im = 1.2;
	}
	else if (ft_strncmp(fractal_type, "julia", 6) == 0)
	{
		data->min_re = -2.0;
		data->max_re = 2.0;
		data->min_im = -2.0;
		data->max_im = 2.0;
	}
	else
	{
		ft_printf("Usage: ./fractol mandelbrot | julia [cRe cIm]\n");
		exit(EXIT_FAILURE);
	}
}

static int	init_data(t_data *data, char *fractal_type)
{
	data->max_iter = 60;
	set_fractal_limits(data, fractal_type);
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

static int	choose_fractal(char **argv, int argc, t_data *data)
{
	data->fractal_type = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		data->fractal_type = 1;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0
		&& argc == 4 && !set_julia_params(argv, data))
	{
		data->fractal_type = 2;
		set_julia_params(argv, data);
	}
	else
	{
		ft_printf("Use 'mandelbrot' | 'julia [c_re c_im]'.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc < 2)
	{
		ft_printf("Usage: ./fractol mandelbrot | julia [cRe cIm]\n");
		return (EXIT_FAILURE);
	}
	if (choose_fractal(argv, argc, &data) == 1)
		return (0);
	if (!init_data(&data, argv[1]))
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0))
	{
		ft_printf("ERROR: Failed to put image to window\n");
		cleanup(&data);
		return (EXIT_FAILURE);
	}
	if (data.fractal_type == 1)
		draw_mandelbrot(&data);
	else if (data.fractal_type == 2)
		draw_julia(&data);
	mlx_scroll_hook(data.mlx, handle_scroll, &data);
	mlx_key_hook(data.mlx, handle_keys, &data);
	mlx_loop(data.mlx);
	return (cleanup(&data), EXIT_SUCCESS);
}
