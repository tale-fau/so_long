/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:52:02 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/08 18:18:56 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	while (data->ligne > -1)
	{
		free(data->map[data->ligne]);
		data->ligne--;
	}
	free(data->map);
	free(data->linear_map);
	exit(0);
	return (0);
}