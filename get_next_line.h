/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:28:57 by dgutin            #+#    #+#             */
/*   Updated: 2021/07/20 14:03:46 by dgutin           ###   ########.fr       */
/*   Updated: 2021/05/11 16:41:01 by dgutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_linebool(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoined(char *s1, char *s2);
char	*ft_gnl(char *cat);
char	*ft_free(char *str);

#endif
