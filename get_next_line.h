/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:28:57 by dgutin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/27 20:20:42 by dgutin           ###   ########.fr       */
=======
/*   Updated: 2021/05/11 16:41:01 by dgutin           ###   ########.fr       */
>>>>>>> 836eef1944d67660ff26f9d02ef78920411e9ea7
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
<<<<<<< HEAD
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoined(char *s1, char const *s2);
int		ft_error(int fd, char **line);
=======
char	*ft_strjoined(char const *s1, char const *s2);
>>>>>>> 836eef1944d67660ff26f9d02ef78920411e9ea7
int		ft_free(char *str);
int		ft_gnl(char *cat, char **line);

#endif
