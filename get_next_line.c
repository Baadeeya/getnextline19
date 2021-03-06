/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:15:51 by dgutin            #+#    #+#             */
/*   Updated: 2021/06/25 16:49:54 by dgutin           ###   ########.fr       */
/*   Updated: 2021/05/11 16:42:11 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linebool(char *str)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

char	*ft_strjoined(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	x;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2)));
	if (!join)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	x = 0;
	while (x < ft_strlen(s2))
	{
		join[i] = s2[x];
		i++;
		x++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

int	ft_gnl(char *cat, char **line)
{
	char	*tmp;
	int		x;

	x = 0;
	*line = ft_substr(cat, 0, ft_linebool(cat));
	tmp = ft_substr(cat, ft_linebool(cat) - 1, ft_strlen(cat));
	if (!tmp || !*line)
		return (0);
	while (tmp[x])
	{
		cat[x] = tmp[x];
		x++;
	}
	cat[x] = '\0';
	free(tmp);
	if (!cat)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			o;
	char		*buf;
	static char	*cat[OPEN_MAX];

//	*line = NULL;
	o = 1;
	if (o != 1 || fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(buf, -1));
	while (ft_linebool(cat[fd]) < 0 && o)
	{
		o = (int)read(fd, buf, BUFFER_SIZE);
		if (o < 0)
			return (ft_free(buf, -1));
		if (o == 0)
			free(cat[fd]);
		buf[o] = '\0';
		cat[fd] = ft_strjoined(cat[fd], buf);
		if (!cat[fd])
			return (ft_free(buf, -1));
	}
	if (!ft_gnl(cat[fd], line))
		return (ft_free(buf, -1));
	free(buf);
	//free(cat[fd]);
	return (o != 0);
}
