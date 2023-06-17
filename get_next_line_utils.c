/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:54:08 by dagutin           #+#    #+#             */
/*   Updated: 2023/06/17 14:54:12 by dagutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (pointer && *pointer)
	{
		if (*pointer == (char) c)
			return (pointer);
		pointer++;
	}
	if (pointer && *pointer == 0 && (char) c == 0)
		return (pointer);
	return (NULL);
}

static size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s && s[count])
		count++;
	return (count);
}

char	*ft_substr(char *s, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*new;

	if (!s1)
		return (NULL);
	new = (char *) malloc(ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*cat;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	cat = (char *)malloc(sizeof(char) * (len + 1));
	if (cat == NULL)
		return (NULL);
	while (*s1 != '\0')
		cat[i++] = *s1++;
	while (*s2 != '\0')
		cat[i++] = *s2++;
	cat[i] = '\0';
	return (cat);
}
