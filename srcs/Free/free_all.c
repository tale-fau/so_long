/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:00:58 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/13 14:59:01 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_ligne)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}
