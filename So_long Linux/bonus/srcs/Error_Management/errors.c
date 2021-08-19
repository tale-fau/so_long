/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:07:48 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 17:23:06 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	suite_suite_suite_errors(int i)
{
	if (i == 30)
		ft_putstr_fd("Error\nInvalid file\n", 2);
	else if (i == 31)
		ft_putstr_fd("Error\nArgument is a directory\n", 2);
	else if (i == 32)
		ft_putstr_fd("Error\nInvalid symbol on the map\n", 2);
	else if (i == 33)
		ft_putstr_fd("Error\nMore than one character on the map\n", 2);
	return (1);
}

int	suite_suite_errors(int i)
{
	if (i >= 30)
		suite_suite_suite_errors(i);
	else if (i == 20)
		ft_putstr_fd("Error\nProblem check read joinGNL\n", 2);
	else if (i == 21)
		ft_putstr_fd("Error\nProblem malloc GNL\n", 2);
	else if (i == 22)
		ft_putstr_fd("Error\nProblem malloc map3d\n", 2);
	else if (i == 23)
		ft_putstr_fd("Error\nMap too big\n", 2);
	else if (i == 24)
		ft_putstr_fd("Error\nCannot load textures\n", 2);
	else if (i == 25)
		ft_putstr_fd("Error\nMap too big\n", 2);
	else if (i == 26)
		ft_putstr_fd("Error\nToo much movements !\n", 2);
	else if (i == 27)
		ft_putstr_fd("Error\nIssue texture enemy\n", 2);
	else if (i == 28)
		ft_putstr_fd("Error\nNo room for the dog :(\n", 2);
	return (1);
}

int	suite_errors(int i)
{
	if (i >= 20)
		suite_suite_errors(i);
	else if (i == 10)
		ft_putstr_fd("Error\nmap composition\n", 2);
	if (i == 11)
		ft_putstr_fd("Error\nclose\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nformat of argument\n", 2);
	else if (i == 13)
		ft_putstr_fd("Error\nassemble linear\n", 2);
	else if (i == 14)
		ft_putstr_fd("Error\nNon rectangular map\n", 2);
	else if (i == 15)
		ft_putstr_fd("Error\nNumber of lines / columns over int max\n",
			2);
	else if (i == 16)
		ft_putstr_fd("Error\nTop or bottom wall incomplete\n", 2);
	else if (i == 17)
		ft_putstr_fd("Error\nLeft or right wall incomplete\n", 2);
	else if (i == 18)
		ft_putstr_fd("Error\nNon rectangular map\n", 2);
	else if (i == 19)
		ft_putstr_fd("Error\nLack of special symbol\n", 2);
	return (1);
}

int	handle_errors(int i)
{
	if (i >= 10)
		suite_errors(i);
	else if (i == 404)
		return (1);
	if (i == 1)
		ft_putstr_fd("Error\nExtension\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nNumber of arguments\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nmlx initialization\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nnew_window\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nnew_image\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nmalloc buf\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nopen\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nread\n", 2);
	exit(1);
	return (1);
}
