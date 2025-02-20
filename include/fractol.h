/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:22:04 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/06 13:12:37 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 720
# define HEIGHT 404

typedef struct s_complex
{
	double	c_real;
	double	c_im;
}			t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		minRe;
	double		maxRe;
	double		minIm;
	double		maxIm;
	int			maxIter;
}				t_data;

void		draw_mandelbrot(t_data *data);
void		handle_scroll(double xoffset, double yoffset, void *param);
void		handle_keys(mlx_key_data_t keydata, void *param);

#endif
