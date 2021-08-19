/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:37:28 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 16:43:53 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char *s2, int nb)
{
	char	*str;
	char	*to_free1;
	char	*to_free2;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0)
		return (NULL);
	to_free1 = (char *)s1;
	to_free2 = (char *)s2;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + ft_strlen(s1), s2, len_s2 + 1);
	if (to_free1 && (nb == 0 || nb == 2) && nb != -1)
		free(to_free1);
	if (to_free2 && (nb == 1 || nb == 2) && nb != -1)
		free(to_free2);
	to_free1 = 0;
	to_free2 = 0;
	return (str);
}
