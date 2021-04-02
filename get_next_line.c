/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:15:51 by dgutin            #+#    #+#             */
/*   Updated: 2021/04/02 18:18:07 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linebool(char *str)
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
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoined(char const *s1, char const *s2)
{
	char	*join;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2)));
	if (!join)
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

int	ft_gnl(int i, char *cat, char *buf, char **line)
{
	char	*tmp;

	tmp = NULL;
	i = (ft_linebool(cat) - 1);
	*line = ft_substr(cat, 0, i);
	if (!*line)
		return (0);
	tmp = NULL;
	cat = ft_swap(tmp, cat, i, buf);
	if (!cat)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	int			o;
	char		*buf;
	char		*tmp;
	static char	*cat;

	o = 1;
	if (o != 1 || fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (!ft_linebool(cat) && o)
	{
		o = (int)read(fd, buf, BUFFER_SIZE);
		if (o < 0)
			return (ft_free(buf));
		buf[o] = 0;
		cat = ft_strjoined(cat, buf);
		if (!cat)
			return (-1);
	}
	if (!ft_gnl(i, cat, buf, line))
		return (-1);
	return (o != 0);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	fd = open(("lol.txt"), O_RDONLY);
	while (i < 6)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		ret = get_next_line(fd, &line);
		printf("|%d| |%s|\n", ret, line);
		i++;
	}
	free((void *)line);
}
