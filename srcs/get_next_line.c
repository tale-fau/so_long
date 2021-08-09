/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:49:40 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/09 16:37:49 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_join_gnl(char *str, char *buffer)
{
	int		len_str;
	int		len_totale;
	char	*newline;

	if (!buffer)
		return (NULL);
	len_str = ft_strlen(str);
	len_totale = len_str + ft_strlen(buffer);
	newline = (char *)malloc(sizeof(char) * (len_totale + 1));
	if (newline == NULL)
		return (NULL);
	ft_init(newline, 0, (len_totale + 1));
	if (str)
		ft_strcpy(newline, str);
	ft_strcat(newline, buffer);
	free((char *)str);
	return (newline);
}

char	*ft_get_first_line(char *str, t_data *data)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ft_realloc(data->map[data->i], i);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_get_remain(char *str)
{
	int		i;
	int		len;
	int		remain_len;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	remain_len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	remain_len = ft_strlen(str) - len;
	ret = (char *)malloc(sizeof(char) * (remain_len + 1));
	if (ret == NULL)
		return (NULL);
	while (str[++len])
		ret[i++] = str[len];
	ret[i] = '\0';
	free(str);
	return (ret);
}

int	get_next_line(int fd, t_data *data)
{
	int			ret_read;
	static char	*str;
	char		*buffer;

	ret_read = 1;
	data->nl_count = 0;
	buffer = (char *)malloc(sizeof(char));
	if (buffer == NULL)
		return (-1);
	while (!ft_check(str, data) && ret_read != 0)
	{
		ret_read = read(fd, buffer, 1);
		if (ret_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret_read] = '\0';
		str = ft_join_gnl(str, buffer);
	}
	free(buffer);
	ft_realloc(data->map, data->nl_count);
	data->map[data->i] = (char *)malloc(sizeof(char));
	data->map[data->i] = ft_get_first_line(str, data);
	str = ft_get_remain(str);
	if (ret_read == 0)
		return (0);
	return (1);
}
