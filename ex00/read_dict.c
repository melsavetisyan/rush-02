/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:08:30 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 01:22:39 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file_simple(char *filename)
{
	int		fd;
	int		bytes;
	char	buffer[1024];
	char	*content;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buffer, 1024);
	content = malloc(bytes + 1);
	i = -1;
	while (++i < bytes)
		content[i] = buffer[i];
	content[bytes] = '\0';
	close(fd);
	return (content);
}
