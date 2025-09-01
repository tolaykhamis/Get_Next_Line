/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:06:34 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/01 17:54:35 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char	*ft_strnjoin(char *s1, char  *s2, int n );
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char *extract_line(char *holder);
char *cut(char *holder);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
#endif