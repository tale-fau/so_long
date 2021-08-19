/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:03:06 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/18 18:53:17 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**set_path_number(void)
{
	char	*path;
	char	**s_path;

	path = NULL;
	s_path = NULL;
	path = ft_strdup("txt/0.xpm ");
	path = ft_strjoinfree(path, "txt/1.xpm txt/2.xpm txt/3.xpm ", 0);
	path = ft_strjoinfree(path, "txt/4.xpm txt/5.xpm txt/6.xpm ", 0);
	path = ft_strjoinfree(path, "txt/7.xpm txt/8.xpm txt/9.xpm", 0);
	if (path == NULL)
		return (0);
	s_path = ft_split(path, ' ');
	if (s_path == NULL)
		return (NULL);
	free(path);
	return (s_path);
}
