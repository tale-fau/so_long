/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:08:13 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/09 16:34:13 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
	mlx_hook(data->window_ptr, 2, 1L << 0, key_manager, &data);
	mlx_hook(data->window_ptr, 17, 1L << 2, mouse_manager, &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}