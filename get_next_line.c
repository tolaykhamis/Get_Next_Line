/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:30 by tkhamis           #+#    #+#             */
/*   Updated: 2025/09/04 11:37:17 by marvin           ###   ########.fr       */
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
	while(holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
    	line = ft_calloc(i + 2, sizeof(char)); 
	else
    	line = ft_calloc(i + 1, sizeof(char));
	if(!line)
		return NULL;
	i = 0;
	while(holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if(holder[i] == '\n')
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
	if(!remaining)
		return NULL;	
	while (holder[i])
		remaining[j++] = holder[i++];
	remaining[j] = '\0';
	free(holder);
	return (remaining);
}

static char	*reader(int fd, char *holder)
{
	char	*buf;
	int		n;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(holder, '\n'))
	{
		holder = read_chunk(fd, holder, buf, &n);
		if (!holder || n <= 0)
			break ;
	}
	free(buf);
	return (holder);
}

static char	*read_chunk(int fd, char *holder, char *buf, int *n)
{
	*n = read(fd, buf, BUFFER_SIZE);
	if (*n < 0)
	{
		free(buf);
		free(holder);
		return (NULL);
	}
	if (*n == 0)
		return (holder);
	buf[*n] = '\0';
	holder = ft_strnjoin(holder, buf, *n);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder[fd] = reader(fd, holder[fd]);
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