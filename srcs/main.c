/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:48:03 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/13 14:34:53 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)data;
	if (ac == 2)
	{
		check_extension(av[1]);
		data_init(&data);
		ft_map_validity(av[1], &data);
		mlx_initialize(&data);
		color_image(&data);
		mlx_put_image_to_window(data.mlx_ptr, data.window_ptr,
			data.img_ptr, 0, 0);
		mlx_hook(data.window_ptr, 2, 1L << 0, key_manager, &data);
		mlx_hook(data.window_ptr, 17, 1L << 2, mouse_manager, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		return (handle_errors(2));
}