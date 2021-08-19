/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:19:26 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 15:34:05 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	enemy_move(t_data *data)
{
	if (data->map[data->enemy.pos[0]][data->enemy.pos[1] + 1] != '1'
		&& data->enemy.right)
		data->enemy.pos[1] += 1;
	else if (data->map[data->enemy.pos[0]][data->enemy.pos[1] + 1] == '1'
		&& data->enemy.right)
		data->enemy.right = 0;
	else if (data->map[data->enemy.pos[0]][data->enemy.pos[1] - 1] != '1'
		&& !data->enemy.right)
		data->enemy.pos[1] -= 1;
	else if (data->map[data->enemy.pos[0]][data->enemy.pos[1] - 1] == '1'
		&& !data->enemy.right)
		data->enemy.right = 1;
	return (0);
}
