/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:22:04 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:09 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 900
# define HEIGHT 600

typedef struct s_complex
{
	double	c_re;
	double	c_im;
}			t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		scale_re;
	double		scale_im;
	int			max_iter;
}				t_data;

void		draw_mandelbrot(t_data *data, t_complex *comp);
void		handle_scroll(double xoffset, double yoffset, void *param);
void		handle_keys(mlx_key_data_t keydata, void *param);
void		cleanup(t_data *data);
void		handle_close(void *param);

#endif
