/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:16:53 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 13:42:09 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**set_path(void)
{
	char	*path;
	char	**s_path;

	path = NULL;
	s_path = NULL;
	path = ft_strdup("txt/w.xpm ");
	path = ft_strjoinfree(path, "txt/g.xpm txt/c.xpm txt/c2.xpm ", 0);
	path = ft_strjoinfree(path, "txt/e.xpm txt/e2.xpm txt/p.xpm ", 0);
	path = ft_strjoinfree(path, "txt/p2.xpm txt/d.xpm ", 0);
	if (path == NULL)
		return (NULL);
	s_path = ft_split(path, ' ');
	if (s_path == NULL)
		return (NULL);
	free(path);
	set_path_number();
	return (s_path);
}

int	load_textures(t_data *data)
{
	char	**path;
	int		i;

	i = 0;
	path = set_path();
	if (path == NULL)
		return (handle_errors(24));
	while (i < 9)
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

int	load_numbers(t_data *data)
{
	char	**path;
	int		i;

	i = 0;
	path = set_path_number();
	if (path == NULL)
		return (handle_errors(24));
	while (i < 10)
	{
		data->mvcount.mv[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				path[i], &data->mvcount.xwidth[i], &data->mvcount.yheight[i]);
		if (!data->mvcount.mv[i])
		{
			free_tab(path);
			return (handle_errors(24));
		}
		i++;
	}
	free_tab(path);
	return (0);
}
