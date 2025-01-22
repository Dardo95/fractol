/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:22:04 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/22 12:52:53 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 1980
# define HEIGHT 800

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

#endif
