/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:16:53 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 16:28:11 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	load_textures(t_data *data)
{
	char	**path;
	int		i;

	path = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		data->texts[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				path[i], &data->xwidth[i], &data->yheight[i]);
		if (!data->texts[i])
		{
			free_tab(path);
			return (handle_errors(24));
		}
		i++;
	}
	free_tab(path);
	return (0);
}
