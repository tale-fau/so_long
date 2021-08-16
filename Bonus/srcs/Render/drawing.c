/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 20:03:35 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	draw_remain(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
		anim_c(data, i, j);
	if (data->map[data->player_pos[0]][data->player_pos[1]] == 'C'
		|| data->map[data->player_pos[0]][data->player_pos[1]] == 'P')
		data->map[data->player_pos[0]][data->player_pos[1]] = '0';
	anim_p(data);
	return (0);
}

int	draw_1_and_E(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[0], j * 16, i * 16);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[1], j * 16, i * 16);
	return (0);
}

int	color_image(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->max_ligne)
	{
		j = 0;
		while (j < data->max_colonne)
		{
			if (data->map[i][j] == '1' || data->map[i][j] == 'E')
				draw_1_and_E(data, i, j);
			else if (data->map[i][j] != '1')
				mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
					data->texts[1], j * 16, i * 16);
			draw_remain(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
