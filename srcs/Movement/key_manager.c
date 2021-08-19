/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 20:42:08 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 16:26:08 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_manager(int keycode, t_data *data)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	if (keycode == 2)
		right_arrow(data);
	if (keycode == 0)
		left_arrow(data);
	if (keycode == 13)
		up_arrow(data);
	if (keycode == 1)
		down_arrow(data);
	if (keycode == 53)
		ft_exit(data);
	return (0);
}

int	mouse_manager(t_data *data)
{
	ft_exit(data);
	return (0);
}
