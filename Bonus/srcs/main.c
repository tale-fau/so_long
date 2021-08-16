/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:48:03 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 18:35:06 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		check_extension(av[1]);
		data_init(&data);
		ft_map_validity(av[1], &data);
		mlx_initialize(&data);
		load_textures(&data);
		data.res_y = (int)(data.max_ligne * data.yheight[4]);
		data.res_x = (int)(data.max_colonne * data.xwidth[4]);
		data.window_ptr = mlx_new_window(data.mlx_ptr, data.res_x,
				data.res_y, "So_long");
		data.img_ptr = mlx_new_image(data.mlx_ptr, data.res_x, data.res_y);
		mlx_hook(data.window_ptr, 2, 1L << 0, key_manager, &data);
		mlx_hook(data.window_ptr, 17, 1L << 2, mouse_manager, &data);
		mlx_loop_hook(data.mlx_ptr, color_image, &data);
		mlx_loop(data.mlx_ptr);
		return (0);
	}
	else
		return (handle_errors(2));
}
