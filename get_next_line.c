/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <tkhamis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:05:30 by tkhamis           #+#    #+#             */
/*   Updated: 2025/08/31 17:29:42 by tkhamis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char buf[BUFFER_SIZE + 1];
    static char *holder;
    int n = read (fd, buf, BUFFER_SIZE);
    int i = 0;
    holder = malloc(n + 1);
    while (i < n && buf[i] != '\n')
    {
     holder[i] = buf[i]; 
     i++;
    }
    holder[i] = '\0';
    return (holder);
}

int main()
{
    int fd = open("test.txt",O_RDONLY);
    printf("%s",get_next_line(fd));
}