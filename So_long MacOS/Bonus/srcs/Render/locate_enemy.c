/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:26:53 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/18 20:16:39 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	scan(t_data *data)
{
	int	ligne;
	int	colonne;

	ligne = 1;
	while (data->map[ligne])
	{
		colonne = 1;
		while (data->map[ligne][colonne])
		{
			if (data->map[ligne][colonne] == '0')
			{
				data->enemy.pos[0] = ligne;
				data->enemy.pos[1] = colonne;
				return (0);
			}
			colonne++;
		}
		ligne++;
	}
	return (handle_errors(28));
}

int	locate_enemy(t_data *data)
{
	if (scan(data) != 0)
		return (1);
	data->map[data->enemy.pos[0]][data->enemy.pos[1]] = 'D';
	return (0);
}
