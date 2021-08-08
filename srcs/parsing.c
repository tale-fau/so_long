/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:44:37 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/08 18:18:55 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_compo(char c, t_data *data)
{
	if (data->ligne == 0 || (data->map[data->ligne]
			&& !data->map[data->ligne + 1]))
	{
		if (c == '1')
			return (0);
		else
			return (handle_errors(16));
	}
	if (data->colonne == 0 || !data->map[data->ligne][data->colonne + 1])
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
			data->player_pos[0] = data->ligne;
			data->player_pos[1] = data->colonne;
		}
		return (0);
	}
	else
		return (handle_errors(19));
}

int	ft_verif(t_data *data)
{
	int	compare;

	compare = ft_strlen(data->map[0]);
	data->ligne = 0;
	while (data->map[data->ligne])
	{
		data->colonne = 0;
		while (data->map[data->ligne][data->colonne])
		{	
			if (ft_check_compo(data->map[data->ligne][data->colonne]
				, data) != 0)
				return (handle_errors(10));
			data->colonne++;
		}
		if (data->ligne > 0)
		{
			if (compare != data->colonne)
				return (handle_errors(18));
		}
		data->ligne++;
	}
	if (data->ligne == data->colonne)
		return (handle_errors(14));
	if (data->ligne > INT_MAX || data->colonne > INT_MAX)
		return (handle_errors(15));
	return (0);
}

int	ft_map_validity(char *path, t_data *data)
{
	int	ret_gnl;
	int	fd;
	int	ret_verif;

	ret_gnl = 42;
	fd = open(path, O_RDONLY);
	data->i = 0;
	data->map = (char **)malloc(sizeof(char *) * 1000);
	while (ret_gnl != 0)
	{
		ret_gnl = get_next_line(fd, data);
		data->i++;
	}
	data->map[data->i] = NULL;
	close(fd);
	ret_verif = ft_verif(data);
	if (ret_verif != 0)
		return (handle_errors(404));
	if (data->sym_c < 1 || data->sym_e < 1 || data->sym_p != 1)
		return (handle_errors(19));
	return (0);
}
