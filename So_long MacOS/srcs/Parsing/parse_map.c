/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:49:40 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 16:09:04 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_3dmap(char *path, t_data *data)
{
	int		fd;
	int		ret;
	char	buff[5000];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (handle_errors(26));
	ft_bzero(buff, 5000);
	while (1)
	{
		ret = read(fd, buff, 5000);
		if (ret < 0)
			return (handle_errors(27));
		if (ret == 4999)
			return (handle_errors(23));
		if (ret == 0)
			break ;
	}
	data->map = ft_split(buff, '\n');
	return (0);
}
