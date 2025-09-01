/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:30 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/01 17:33:02 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
    static char *holder;
    char buf[BUFFER_SIZE + 1];
    char *line;
    int n;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    line = extract_line(holder);
    while (!line) {
        n = read(fd, buf, BUFFER_SIZE);
        if (n <= 0)
            break;

        buf[n] = '\0'; 
        holder = ft_strnjoin(holder, buf, n);
        if (!holder)
            return NULL;

        line = extract_line(holder);
    }

    if (line) {
        holder = cut(holder);
        return line;
    }
    if (holder) {
        line = ft_strdup(holder);
        free(holder);
        holder = NULL;
        return line;
    }
    return NULL;
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); 
    }
}