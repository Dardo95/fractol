/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:42:19 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/25 22:44:57 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	cleanup(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
	{
		mlx_delete_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->mlx)
	{
		mlx_terminate(data->mlx);
		data->mlx = NULL;
	}
}
