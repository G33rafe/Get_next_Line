/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajacque <rajacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:21:02 by rajacque          #+#    #+#             */
/*   Updated: 2022/11/10 00:05:12 by rajacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *buffer)
{
	size_t	i;
	char	*new_line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	new_line = ft_calloc(sizeof(char), (ft_strlen(buffer) + 1));
	if (!new_line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		new_line[i] = buffer[i];
	return (new_line);
}

char	*ft_new_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	while (buffer[i++])
		new_buffer[j++] = buffer[i];
	free (buffer);
	return (new_buffer);
}

void	*ft_flush_mem(char **buffer, char *line)
{
	free(line);
	if (buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_value;

	read_value = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (read_value != 0 && !ft_strchr(buffer, '\n'))
	{
		read_value = read(fd, line, BUFFER_SIZE);
		if (read_value == -1)
			return (ft_flush_mem(&buffer, line));
		line[read_value] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	line = ft_new_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}
