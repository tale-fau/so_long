/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:59:32 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/18 19:42:12 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	scan_map(t_data *data, char c)
{
	int	ligne;
	int	colonne;

	ligne = 0;
	while (data->map[ligne])
	{
		colonne = 0;
		while (data->map[ligne][colonne])
		{
			if (data->map[ligne][colonne] == c)
				return (1);
			colonne++;
		}
		ligne++;
	}
	return (0);
}

int	exit_win(t_data *data)
{
	if (scan_map(data, 'C') == 1)
		return (0);
	else
	{
		ft_putstr_fd("You Win !\n", 1);
		ft_exit(data);
		return (0);
	}
	return (0);
}
