/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:11:22 by dgutin            #+#    #+#             */
/*   Updated: 2021/07/21 15:36:26 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*psrc;
	char		*pdst;

	i = -1;
	psrc = src;
	pdst = dst;
	if (dst == 0 && src == dst)
		return (0);
	if (pdst < psrc)
		while (++i < len)
			pdst[i] = psrc[i];
	else
		while (len--)
			pdst[len] = psrc[len];
	return (dst);
}
