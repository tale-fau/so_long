/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:12:25 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 15:08:22 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	set_path_load_enemy(t_data *data)
{
	char	*path;

	path = ft_strdup("txt/d.xpm");
	data->enemy.txt = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&data->enemy.xwidth, &data->enemy.yheight);
	if (!data->enemy.txt)
	{
		free(path);
		return (handle_errors(27));
	}
	locate_enemy(data);
	data->enemy.right = 1;
	free(path);
	return (0);
}
