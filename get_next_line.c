/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:15:51 by dgutin            #+#    #+#             */
/*   Updated: 2021/01/11 18:07:03 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoined(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		x;

	if (!(cat = malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2)))))
		return (NULL);
	i = -1;
	while (s1[++i])
		cat[i] = s1[i];
	x = -1;
	while (s2[++x])
		cat[i++] = s2[x];
	cat[i] = '\0';
	return (cat);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	int			x;
	char		*buf;

	i = -1;
	x = -1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	read(fd, buf, BUFFER_SIZE);
	while (*line[++i])
		
	x = -1;
}
