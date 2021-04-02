/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:28:57 by dgutin            #+#    #+#             */
/*   Updated: 2021/04/02 17:47:11 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_linebool(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoined(char const *s1, char const *s2);
int		ft_error(int fd, char **line);
int		ft_free(char *str);
int		ft_gnl(int i, char *cat, char *buf, char **line);
char	*ft_swap(char *tmp, char *cat, int i, char *buf);

#endif
