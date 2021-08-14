/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:42:27 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/14 19:59:24 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	mlx_initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	return (0);
}

int	data_init(t_data *data)
{
	data->coins = 42;
	data->key_count = 0;
	data->index = 0;
	data->max_ligne = 0;
	data->max_colonne = 0;
	data->ret_read = 42;
	data->size_game = 16;
	return (0);
}