/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:06:04 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/02 16:21:55 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}



char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		len1;
	char	*out;

	len1 = s1 ? ft_strlen(s1) : 0;
	out = ft_calloc(len1 + n + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (s1)
		ft_memcpy(out, s1, len1);
	ft_memcpy(out + len1, s2, n);
	out[len1 + n] = '\0';
	free(s1);
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
