/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:59:27 by tale-fau          #+#    #+#             */
/*   Updated: 2021/07/27 23:39:23 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;
	size_t	cur_size;

	if (ptr == 0)
		return (malloc(size));
	cur_size = sizeof(ptr);
	if (size <= cur_size)
		return (ptr);
	newptr = malloc(size);
	ft_memcpy(ptr, newptr, cur_size);
	free(ptr);
	return (newptr);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			data->nl_count++;
			return (1);
		}
	}
	return (0);
}

void	ft_init(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
}
