/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 15:10:27 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	draw_remain(t_data *data, int i, int j)
{
	if (data->key_count > 999)
		return (handle_errors(26));
	else
		display_mvcount(data);
	if (data->map[i][j] == 'C')
		anim_c(data, i, j);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->enemy.txt, data->enemy.pos[1] * 16,
		data->enemy.pos[0] * 16);
	anim_p(data);
	if (data->map[data->player_pos[0]][data->player_pos[1]] == 'C'
		|| data->map[data->player_pos[0]][data->player_pos[1]] == 'P')
		data->map[data->player_pos[0]][data->player_pos[1]] = '0';
	if (data->map[data->enemy.pos[0]][data->enemy.pos[1]] == 'D')
		data->map[data->enemy.pos[0]][data->enemy.pos[1]] = '0';
	if (data->player_pos[0] == data->enemy.pos[0]
		&& data->player_pos[1] == data->enemy.pos[1])
	{
		ft_putstr_fd("You lost :'(\n", 1);
		ft_exit(data);
	}
	return (0);
}

int	draw_1_and_E(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[0], j * 16, i * 16);
	else if (data->map[i][j] == 'E')
		anim_e(data, i, j);
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
