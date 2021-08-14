/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:54:46 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/13 15:38:36 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	new_window(t_data *data)
{
	if (data->max_colonne <= 100 || data->max_ligne <= 70)
		data->window_ptr = mlx_new_window(data->mlx_ptr, data->max_colonne
				* data->size_game, data->max_ligne
				* data->size_game, "So Long");
	else
		data->window_ptr = mlx_new_window(data->mlx_ptr,
				data->max_colonne, data->max_ligne, "So Long");
	if (data ->window_ptr == NULL)
		return (1);
	return (0);
}