/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:15:51 by dgutin            #+#    #+#             */
/*   Updated: 2021/01/14 14:09:42 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_linebool(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i + 1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoined(char const *s1, char const *s2)
{
	char	*join;

	if (!(join = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + 1 + ft_strlen(s2)))))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(join, s1, ft_strlen(s1));
	ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2));
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((void *)s1);
	return (join);
}

char	*ft_stock(char *cat, char *buf, int o, int fd)
{
	while (!ft_linebool(cat) && o)
	{
		if ((o = (int)read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free((void *)buf);
			return (NULL);
		}
		buf[o] = 0;
		if (!(cat = ft_strjoined(cat, buf)))
			return (NULL);
	}
	return (cat);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	int			o;
	char		*buf;
	char		*tmp;
	static char	*cat;

	if (ft_error(fd, line))
		return (-1);
	o = 1;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!(cat = ft_stock(cat, buf, o, fd)))
		return (-1);
	free((void *)buf);
	i = (ft_linebool(cat) - 1);
	if (!(*line = ft_substr(cat, 0, i)))
		return (-1);
	if (!(tmp = ft_substr(cat, i + 1, ft_strlen(cat) - i - 1)))
		return (-1);
	free((void *)cat);
	if (!(cat = ft_substr(tmp, 0, ft_strlen(tmp))))
		return (-1);
	return (o == 0 ? 0 : 1);
}

#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	fd = open(("lol.txt"), O_RDONLY);
	while (i < 5)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		ret = get_next_line(fd, &line);
		printf("|%d| |%s|\n", ret, line);
		i++;
	}
}
