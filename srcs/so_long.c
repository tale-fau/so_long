/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:26:48 by tale-fau          #+#    #+#             */
/*   Updated: 2021/07/27 23:39:24 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	new_window(t_data *data)
{
	data->window_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "New Window");
	if (data ->window_ptr == NULL)
		return (1);
	return (0);
}

int	new_image(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	if (data->img_ptr == NULL)
		return (1);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}

int	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if ((av[i - 4] == '.' && av[i - 3] == 'b' && av[i - 2] == 'e'
			&& av[i - 1] == 'r' && av[i] == '\0'))
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (handle_errors(2));
	if (check_extension(av[1]) != 0)
		return (handle_errors(1));
	if (!av[1])
		return (handle_errors(12));
	if (ft_map_validity(av[1], &data) != 0)
		return (handle_errors(3));
	ft_putstr_fd("Map valide\n", 1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (handle_errors(4));
	if (new_window(&data) == 1)
		return (handle_errors(5));
	if (new_image(&data) == 1)
		return (handle_errors(6));
	color_image(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
