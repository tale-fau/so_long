/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:25:04 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/08 18:18:58 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	right_arrow(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	new_image(data);
	if (data->map[data->player_pos[0]][data->player_pos[1] + 1] == '1')
		return (0);
	else
	{
		data->player_pos[1] += 1;
		ft_putstr_fd("Movement count : ", 1);
		ft_putnbr_fd(++data->key_count, 1);
		ft_putchar_fd('\n', 1);
	}
	color_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
	return (0);
}

int	left_arrow(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	new_image(data);
	if (data->map[data->player_pos[0]][data->player_pos[1] - 1] == '1')
		return (0);
	else
	{
		data->player_pos[1] -= 1;
		ft_putstr_fd("Movement count : ", 1);
		ft_putnbr_fd(++data->key_count, 1);
		ft_putchar_fd('\n', 1);
	}
	color_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
	return (0);
}

int	up_arrow(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	new_image(data);
	if (data->map[data->player_pos[0] - 1][data->player_pos[1]] == '1')
		return (0);
	else
	{
		data->player_pos[0] -= 1;
		ft_putstr_fd("Movement count : ", 1);
		ft_putnbr_fd(++data->key_count, 1);
		ft_putchar_fd('\n', 1);
	}
	color_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
	return (0);
}

int	down_arrow(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	new_image(data);
	if (data->map[data->player_pos[0] + 1][data->player_pos[1]] == '1')
		return (0);
	else
	{
		data->player_pos[0] += 1;
		ft_putstr_fd("Movement count : ", 1);
		ft_putnbr_fd(++data->key_count, 1);
		ft_putchar_fd('\n', 1);
	}
	color_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
	return (0);
}

int	key_manager(int keycode, t_data *data)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	printf("keycode = %i\n", keycode);
	if (keycode == 2)
		right_arrow(data);
	if (keycode == 0)
		left_arrow(data);
	if (keycode == 13)
		up_arrow(data);
	if (keycode == 1)
		down_arrow(data);
	if (keycode == 53)
		ft_exit(data);
	return (0);
}
