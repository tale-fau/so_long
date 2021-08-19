/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:44:37 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 17:36:59 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_special(char c, t_data *data, int ligne, int colonne)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P')
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
		return (handle_errors(32));
}

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
	is_special(c, data, ligne, colonne);
	return (0);
}

int	check_limits(int ligne, int colonne, t_data *data)
{
	if (ligne > INT_MAX || colonne > INT_MAX)
		return (handle_errors(15));
	data->max_ligne = ligne;
	return (0);
}

int	ft_verif(t_data *data)
{
	int	ligne;
	int	colonne;

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
	check_limits(ligne, colonne, data);
	return (0);
}

int	ft_map_validity(char *path, t_data *data)
{
	int	ret_verif;
	int	temp;

	get_3dmap(path, data);
	data->max_colonne = (int)ft_strlen(data->map[0]);
	if (data->max_colonne > 68)
		return (handle_errors(25));
	temp = (int)ft_tablen(data->map);
	if (temp > 70)
		return (handle_errors(25));
	ret_verif = ft_verif(data);
	if (ret_verif != 0)
		return (handle_errors(404));
	if (data->sym_c < 1 || data->sym_e < 1 || data->sym_p < 1)
		return (handle_errors(19));
	if (data->sym_p > 1)
		return (handle_errors(33));
	return (0);
}
