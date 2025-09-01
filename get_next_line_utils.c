/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:06:04 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/01 15:56:44 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*w;
	const unsigned char	*s;

	w = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*w++ = *s++;
	return (dest);
}

char	*ft_strnjoin(char *s1, char  *s2, int n )
{
    int len1 ;
    if(s1)
        len1 = ft_strlen(s1);
    else
        len1 = 0;
    char *out= malloc(len1 + n + 1);
    
    if(s1)
        ft_memcpy(out, s1, len1);
    ft_memcpy(out + len1, s2, n);
    out[len1 + n] = '\0';
    free(s1);
    return(out);
}

char *cut(char *holder)
{
    if (!holder)
        return NULL;

    int i = 0;
    while (holder[i] && holder[i] != '\n')
        i++;

    if (holder[i] == '\0'){
    free(holder);
    return NULL;
    }
    i++; // move past '\n'
    int len = ft_strlen(holder + i);

    char *remaining = malloc(len + 1);
    if (!remaining)
        return NULL;

    ft_memcpy(remaining, holder + i, len);
    remaining[len] = '\0';
    free(holder);
    return remaining;
}

char *extract_line(char *holder)
{
    int i = 0;
    int c = 0;

    if (!holder || !*holder)
        return NULL;

    while (holder[i] && holder[i] != '\n')
        i++;

    char *line = malloc(i + (holder[i] == '\n' ? 2 : 1));
    if (!line)
        return NULL;

    while (holder[c] && holder[c] != '\n') {
        line[c] = holder[c];
        c++;
    }

    if (holder[c] == '\n')
        line[c++] = '\n';

    line[c] = '\0';
    return line;
}


