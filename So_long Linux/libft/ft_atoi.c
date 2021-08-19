/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:33:05 by tale-fau          #+#    #+#             */
/*   Updated: 2021/01/02 13:14:22 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_blank(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *c)
{
	int	i;
	int	sign;
	int	ret;

	ret = 0;
	sign = 1;
	i = 0;
	while (is_blank(c[i]) == 1)
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '+')
			i++;
		else
		{
			sign = -1;
			i++;
		}
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		ret = (ret * 10) + (c[i] - 48);
		i++;
	}
	return (ret * sign);
}
