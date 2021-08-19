/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:51:38 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/16 16:24:53 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extension(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (handle_errors(12));
	while (av[i])
		i++;
	if ((av[i - 4] == '.' && av[i - 3] == 'b' && av[i - 2] == 'e'
			&& av[i - 1] == 'r' && av[i] == '\0'))
		return (0);
	else
		return (handle_errors(1));
}
