/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:30 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/02 16:23:47 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *holder)
{
	int		i;
	char	*line;

	i = 0;
	if (!holder || !*holder)
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	line = ft_calloc(i + (holder[i] == '\n' ? 2 : 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*cut(char *holder)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	j = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		free(holder);
		return (NULL);
	}
	i++;
	remaining = ft_calloc(ft_strlen(holder + i) + 1, sizeof(char));
	if (!remaining)
		return (NULL);
	while (holder[i])
		remaining[j++] = holder[i++];
	remaining[j] = '\0';
	free(holder);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*holder[1024];
	char		*buf;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(holder[fd], '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(buf);
			free(holder[fd]);
			holder[fd] = NULL;
			return (NULL);
		}
		if (n == 0)
			break ;
		buf[n] = '\0';
		holder[fd] = ft_strnjoin(holder[fd], buf, n);
		if (!holder[fd])
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (!holder[fd] || !*holder[fd])
    {
        free(holder[fd]);
        holder[fd] = NULL;
        return (NULL);
    }
	line = extract_line(holder[fd]);
	holder[fd] = cut(holder[fd]);
	return (line);
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
	close(fd);
}