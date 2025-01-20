/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:53:10 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/20 18:24:14 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main()
{

	mlx_t *mlx;

	mlx = mlx_init(1980, 800, "ALELLUUUUYAAAAAAA", true);
	mlx_loop(mlx);

	mlx_terminate(mlx);
}
