/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:40:17 by olcherno          #+#    #+#             */
/*   Updated: 2025/01/08 15:04:50 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		reading(int fd, char **stor);
char	*free_storeg(char *stor, const char *s2);
char	*cutting(char **stor);
char	*allocates_copy(const char *src, int len);
#endif