/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin </var/mail/dgutin>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:09:06 by dgutin            #+#    #+#             */
/*   Updated: 2021/06/25 15:09:35 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_linebool(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
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
	int		i;

	x = -1;
	i = ft_linebool(cat);
	tmp = ft_substr(cat, i, ft_strlen(cat));
	*line = ft_substr(cat, 0, i - 1);
	if (!tmp || !*line)
		return (0);
	while (tmp[++x])
		cat[x] = tmp[x];
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

	*line = NULL;
	o = 1;
	if (o != 1 || fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(buf));
	while (!ft_linebool(cat[fd]) && o)
	{
		o = (int)read(fd, buf, BUFFER_SIZE);
		if (o <= 0)
		{
			if (o == 0)
				free(cat);
			return (ft_free(buf));
		}
		buf[o] = '\0';
		cat[fd] = ft_strjoined(cat[fd], buf);
		if (!cat[fd])
			return (ft_free(buf));
	}
	if (!ft_gnl(cat[fd], line))
		return (ft_free(buf));
	free(buf);
	return (o != 0);
}
