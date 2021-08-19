/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:00:34 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/18 19:41:03 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	anim_p(t_data *data)
{
	static int	animp = 0;

	if (animp <= 50)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->texts[6],
			data->player_pos[1] * 16, data->player_pos[0] * 16);
		animp++;
	}
	else if (animp > 50 || animp <= 100)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->texts[7],
			data->player_pos[1] * 16, data->player_pos[0] * 16);
		animp++;
	}
	if (animp > 100)
		animp = 0;
	return (0);
}

int	anim_c(t_data *data, int i, int j)
{
	static int	animc = 0;

	if (animc <= 50)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[2], j * 16, i * 16);
		animc++;
	}
	else if (animc > 50 || animc <= 100)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[3], j * 16, i * 16);
		animc++;
	}
	if (animc > 100)
		animc = 0;
	return (0);
}

int	anim_e(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->texts[4], j * 16, i * 16);
	if (scan_map(data, 'C') == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->texts[5], j * 16, i * 16);
	return (0);
}
