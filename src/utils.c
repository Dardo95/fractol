/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:42:19 by enogueir          #+#    #+#             */
/*   Updated: 2025/02/26 21:32:28 by enogueir         ###   ########.fr       */
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

int	valid_doble(char *param)
{
	if (param == NULL)
		return (0);
	if (*param == '+' || *param == '-')
		param++;
	while (*param)
	{
		if (ft_isdigit(*param) == 0)
			break ;
		param++;
	}
	if (*param == '.')
		param++;
	while (*param)
	{
		if (ft_isdigit(*param) == 0)
			return (0);
		param++;
	}
	return (1);
}
