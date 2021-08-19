/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:37:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/18 19:03:14 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_tens(int i)
{
	int	n;
	int	ret;

	n = i;
	ret = 0;
	while (n > 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

int	display_mvcount(t_data *data)
{
	int	i;
	int	tmp;

	i = get_tens(data->key_count);
	if (i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[data->key_count], 0, 0);
	else if (i == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[data->key_count / 10], 0, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[data->key_count % 10], 1 * 16, 0);
	}
	else if (i == 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[data->key_count / 100], 0, 0);
		tmp = data->key_count % 100;
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[tmp / 10], 1 * 16, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->mvcount.mv[data->key_count % 10], 2 * 16, 0);
	}
	return (0);
}
