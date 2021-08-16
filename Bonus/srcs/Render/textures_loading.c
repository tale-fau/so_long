/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:16:53 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 19:55:55 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**set_path(void)
{
	char	*path;
	char	**s_path;

	path = NULL;
	s_path = NULL;
	path = ft_strdup("../../txt/1.xpm ");
	path = ft_strjoinfree(path, "../../txt/0.xpm ../../txt/c.xpm ../../txt/c2.xpm ", 0);
	path = ft_strjoinfree(path, "../../txt/e.xpm ../../txt/e2.xpm ../../txt/p.xpm ", 0);
	path = ft_strjoinfree(path, "../../txt/p2.xpm ../../txt/d.xpm ", 0);
	if (path == NULL)
		return (NULL);
	s_path = ft_split(path, ' ');
	if (s_path == NULL)
		return (NULL);
	free(path);
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
		printf("i = %i\n", i);
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

/* int	load_textures_bonus(t_data *data)
{
} */