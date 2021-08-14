/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:55:47 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/13 15:37:41 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	new_image(t_data *data)
{
	if (data->max_colonne <= 100 || data->max_ligne <= 70)
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->max_colonne
				* data->size_game, data->max_ligne * data->size_game);
	else
		data->img_ptr = mlx_new_image(data->mlx_ptr,
				data->max_colonne, data->max_ligne);
	if (data->img_ptr == NULL)
		return (1);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}