/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:15:51 by dgutin            #+#    #+#             */
/*   Updated: 2021/01/12 17:27:12 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>



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

int		ft_linebool(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == '\n')
			return (i);
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

char	*ft_strjoined(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		x;

	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2)))))
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
	{
		join[i] = s1[i];
	}
	x = -1;
	while (s2[++x])
		join[i++] = s2[x];
	join[i] = '\0';
	return (join);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	int			o;
	char		*buf;
	char		*tmp;
	static char	*cat;

	if (!line)
		return (-1);
	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!(cat = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_linebool(cat))
	{
		o = (int)read(fd, buf, BUFFER_SIZE);
		buf[o] = '\0';
		if (!(cat = ft_strjoined(cat, buf)))
			return (-1);
		//		write(1, "penis", 6);
	}
	i = ft_linebool(buf);
	*line = (char *)malloc(sizeof(char) * i + 1);
	ft_memcpy(*line, cat, i);
	if (*line[i - 1] == '\n')
		return (1);
	if (!*line[i - 1])
		return (0);
	else
		return (-1);
	tmp = ft_substr(cat, i, o - i);
	free(cat);
	cat = ft_substr(tmp, 0, o - i);
}

#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	ft_putendl(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

void	add(char *str)
{
	static char	*a;

	if (!a)
		printf("First occurence\n");
	else
		printf("last occurence was : %s\n", a);
	a = str;
}

int 	main(void)
{
	int		fd;
	int		ret;
	char	*str;

	str = NULL;
	if ((fd = open("lol.txt", O_RDONLY)) < 0)
		return (1);
	ret = 12;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		if (ret < 0)
			break;
		printf("%d : '%s'\n", ret, str);
		free(str);
	}
	if ((close(fd)) < 0)
		return (1);
	return (0);
}
