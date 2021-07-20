/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:28 by dgutin            #+#    #+#             */
/*   Updated: 2021/07/20 18:58:57 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

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

char	*ft_gnl(char *cat)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (!cat[0])
		if (ft_linebool(cat) < 0)
			return (NULL);
	line = ft_substr(cat, 0, ft_linebool(cat));
	tmp = ft_substr(cat, ft_linebool(cat) + 1, ft_strlen(cat));
	while (tmp[i] && ft_linebool(cat) >= 0)
	{
		cat[i] = tmp[i];
		i++;
	}
	cat[i] = '\0';
	free(tmp);
	return (line);
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

char	*get_next_line(int fd)
{
	int			o;
	char		*buf;
	static char	*cat;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	o = 1;
	buf = NULL;
	if (o)
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(buf));
	while (ft_linebool(cat) < 0 && o)
	{
		o = (int)read(fd, buf, BUFFER_SIZE);
		if (o < 0)
			return (ft_free(buf));
//		if (o == 0)
//			break ;
		buf[o] = '\0';
		cat = ft_strjoined(cat, buf);
		if (!cat)
			return (ft_free(buf));
	}
	return (ft_gnl(cat));
}
