/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:53:47 by dagutin           #+#    #+#             */
/*   Updated: 2023/06/20 18:17:00 by dagutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif

static char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

static char	*ft_final_line(char **saved_fd)
{
	char	*line;

	if (!(*saved_fd)[0])
	{
		*saved_fd = ft_free(*saved_fd);
		return (*saved_fd);
	}
	line = ft_strdup(*saved_fd);
	if (!line)
	{
		if (*saved_fd)
			*saved_fd = ft_free(*saved_fd);
		return (ft_free(line));
	}
	*saved_fd = ft_free(*saved_fd);
	return (line);
}

static char	*ft_line_fill(char **saved_fd)
{
	char	*temp;
	char	*line;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	if ((*saved_fd)[i] == '\n')
	{
		line = ft_substr((*saved_fd), i + 1);
		if (!(*line))
			return (ft_free(line));
		temp = ft_strdup(&(*saved_fd)[i + 1]);
		if (!temp)
			return (ft_free(temp));
		free(*saved_fd);
		*saved_fd = temp;
	}
	else
		return (ft_final_line(saved_fd));
	return (line);
}

static int	ft_gnl(char **saved, int fd, char *buf, int ret)
{
	char	*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (!saved[fd])
	{
		if (!buf[0])
			return (-1);
		saved[fd] = ft_strdup(buf);
		if (!saved[fd])
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(saved[fd], buf);
		if (!tmp)
		{
			free(tmp);
			return (-1);
		}
		free(saved[fd]);
		saved[fd] = tmp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_gnl(saved, fd, buf, ret);
		if (ret == -1)
			return (NULL);
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (ft_line_fill(&saved[fd]));
}
