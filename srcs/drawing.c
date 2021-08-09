/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:38:24 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/09 18:50:36 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	draw_player(int y, int x, t_data *data)
{
	int	a;
	int	b;

	b = 0;
	while (y + b <= y + 10)
	{
		a = 0;
		while (x + a <= x + 10)
		{
			ft_pixel_put(data, x + a, y + b, 0x21ff00);
			a++;
		}
		b++;
	}
	return (0);
}

int	draw_walls(int y, int x, t_data *data)
{
	int	a;
	int	b;

	b = 0;
	while (y + b <= y + 10)
	{
		a = 0;
		while (x + a <= x + 10)
		{
			ft_pixel_put(data, x + a, y + b, 0xff0000);
			a++;
		}
		b++;
	}
	return (0);
}

int	draw_playgd(int y, int x, t_data *data)
{
	int	a;
	int	b;

	b = 0;
	while (y + b <= y + 10)
	{
		a = 0;
		while (x + a <= x + 10)
		{
			ft_pixel_put(data, x + a, y + b, 0x00ffeb);
			a++;
		}
		b++;
	}
	return (0);
}

int	draw_utils(int y, int x, t_data *data, char c)
{
	int	a;
	int	b;

	b = 0;
	while (y + b <= y + 10)
	{
		a = 0;
		while (x + a <= x + 10)
		{
			if (c == 'C')
/* 				data->text_coin = mlx_xpm_file_to_image(data->mlx_ptr,
						data->coin_xpm, &data->img_width, &data->img_height); */
						ft_pixel_put(data, x + a, y + b, 0xffdd00);
			else if (c == 'E')
				ft_pixel_put(data, x + a, y + b, 0x8900ff);
			a++;
		}
		b++;
	}
	return (0);
}

//				ft_pixel_put(data, x + a, y + b, 0xffdd00);

int	color_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				draw_walls(i * 10, j * 10, data);
			}
			else if (data->map[i][j] == '0' || data->map[i][j] == 'P')
			{
				draw_playgd(i * 10, j * 10, data);
			}
			else if (data->map[i][j] == 'C')
			{	
				draw_utils(i * 10, j * 10, data, 'C');
			}
			else if (data->map[i][j] == 'E')
			{	
				draw_utils(i * 10, j * 10, data, 'E');
			}
			j++;
		}
		i++;
	}
	if (data->map[data->player_pos[0]][data->player_pos[1]] == 'C')
		data->map[data->player_pos[0]][data->player_pos[1]] = '0';
	draw_player(data->player_pos[0] * 10, data->player_pos[1] * 10, data);
	return (0);
}
