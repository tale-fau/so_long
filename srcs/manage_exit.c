/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:52:02 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/09 15:14:40 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	scan_map(t_data *data)
{
	int	ligne;
	int	colonne;

	ligne = 0;
	while (data->map[ligne])
	{
		colonne = 0;
		while (data->map[ligne][colonne])
		{
			if (data->map[ligne][colonne] == 'C')
				return (1);
			colonne++;
		}
		ligne++;
	}
	return (0);
}

int	exit_win(t_data *data)
{
	if (scan_map(data) == 1)
		return (0);
	else
	{
		if (data->map[data->player_pos[0]][data->player_pos[1] + 1] == 'E'
			|| data->map[data->player_pos[0]][data->player_pos[1] - 1] == 'E'
			|| data->map[data->player_pos[0] + 1][data->player_pos[1]] == 'E'
			|| data->map[data->player_pos[0] - 1][data->player_pos[1]] == 'E')
		{
			ft_putstr_fd("You Win !\n", 1);
			ft_exit(data);
		}
		else
			return (0);
	}
	return (0);
}

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