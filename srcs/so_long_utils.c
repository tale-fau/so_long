/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:30:51 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/09 18:50:30 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	data_init(t_data *data)
{
	data->key_count = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (handle_errors(4));
	if (new_window(data) == 1)
		return (handle_errors(5));
	if (new_image(data) == 1)
		return (handle_errors(6));
	/* data->path_player = ;
	data->path_wall = ;
	data->path_coin = ;
	data->path_playgd = ;
	data->path_exit = ; */
	return (0);
}