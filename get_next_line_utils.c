/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:11:22 by dgutin            #+#    #+#             */
/*   Updated: 2021/04/02 18:17:46 by dgutin           ###   ########.fr       */
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
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_free(char *str)
{
	if (str)
		free((void *)str);
	return (-1);
}

char	*ft_swap(char *tmp, char *cat, int i, char *buf)
{
	if (buf)
		free((void *)buf);
	tmp = ft_substr(cat, i + 1, ft_strlen(cat) - i - 1);
	if (!tmp)
		return (NULL);
	free((void *)cat);
	cat = ft_substr(tmp, 0, ft_strlen(tmp));
	if (!cat)
		return (NULL);
	free((void *)tmp);
	return (cat);
}
