/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:41:54 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/26 19:17:36 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	set_julia_params(char **argv, t_data *data)
{
	data->j_c_r = -0.7;
	data->j_c_i = 0.27015;
	if (!valid_doble(argv[2]) || !valid_doble(argv[3]))
	{
		return (EXIT_FAILURE);
	}
	else if (ft_atof(argv[2]) && ft_atof(argv[3]))
	{
		data->j_c_r = ft_atof(argv[2]);
		data->j_c_i = ft_atof(argv[3]);
		return (0);
	}
	return (1);
}
