/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:11:22 by dgutin            #+#    #+#             */
/*   Updated: 2021/01/14 14:03:59 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*psrc;
	char		*pdst;

	i = -1;
	psrc = src;
	pdst = dst;
	if (dst == 0 && src == dst)
		return (0);
	while (++i < n)
		*(pdst + i) = *(psrc + i);
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_error(int fd, char **line)
{
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (1);
	return (0);
}
