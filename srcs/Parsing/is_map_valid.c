/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:44:37 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/14 21:01:38 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_compo(char c, t_data *data, int ligne, int colonne)
{
	if (ligne == 0 || (data->map[ligne] && !data->map[ligne + 1]))
	{
		if (c == '1')
			return (0);
		else
			return (handle_errors(16));
	}
	if (colonne == 0 || !data->map[ligne][colonne + 1])
	{
		if (c == '1')
			return (0);
		else
			return (handle_errors(17));
	}
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == '\n' || c == '\0')
	{
		if (c == 'E')
			data->sym_e++;
		if (c == 'C')
			data->sym_c++;
		if (c == 'P')
		{
			data->sym_p++;
			data->player_pos[0] = ligne;
			data->player_pos[1] = colonne;
		}
		return (0);
	}
	else
		return (handle_errors(19));
}

int	ft_verif(t_data *data)
{
	int	ligne;
	int	colonne;

	data->max_colonne = (int)ft_strlen(data->map[0]);
	ligne = 0;
	while (data->map[ligne])
	{
		colonne = 0;
		while (data->map[ligne][colonne])
		{
			if (ft_check_compo(data->map[ligne][colonne]
				, data, ligne, colonne) != 0)
				return (handle_errors(10));
			colonne++;
		}
		if (ligne > 0)
		{
			if (data->max_colonne != colonne)
				return (handle_errors(18));
		}
		ligne++;
	}
	if (ligne == colonne)
		return (handle_errors(14));
	if (ligne > INT_MAX || colonne > INT_MAX)
		return (handle_errors(15));
	data->max_ligne = ligne;
	return (0);
}

int	ft_map_validity(char *path, t_data *data)
{
	int	ret_verif;

	get_3dmap(path, data);
	ret_verif = ft_verif(data);
	if (ret_verif != 0)
		return (handle_errors(404));
	if (data->sym_c < 1 || data->sym_e < 1 || data->sym_p != 1)
		return (handle_errors(19));
	return (0);
}
