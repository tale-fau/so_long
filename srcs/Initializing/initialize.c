/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:42:27 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/13 15:35:30 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mlx_initialize(t_data *data)
{
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

int	data_init(t_data *data)
{
	data->key_count = 0;
	data->index = 0;
	data->max_ligne = 0;
	data->max_colonne = 0;
	data->ret_read = 42;
	data->size_game = 50;
	return (0);
}