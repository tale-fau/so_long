/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/07/25 18:21:50 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1000)
	{
		while (x < 1000)
		{
			ft_pixel_put(data, x, y, 0xff0000);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_playable_zone(t_data *data)
{
	int	x;
	int	y;

	x = 200;
	y = 200;
	while (y < 801)
	{
		while (x < 801)
		{
			ft_pixel_put(data, x, y, 0x00cdff);
			x++;
		}
		x = 200;
		y++;
	}
	return (0);
}

int	draw_obstacles(t_data *data)
{
	int	x;
	int	y;

	x = 570;
	y = 310;
	while (y < 360)
	{
		while (x < 801)
		{
			ft_pixel_put(data, x, y, 0x00e677);
			x++;
		}
		x = 570;
		y++;
	}
	return (0);
}

int	color_image(t_data *data)
{
	draw_walls(data);
	draw_playable_zone(data);
	draw_obstacles(data);
	return (0);
}
