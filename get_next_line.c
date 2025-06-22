/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:55:00 by marvin            #+#    #+#             */
/*   Updated: 2025/06/22 22:39:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	char	buffer[2];
	char	*sol;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	sol = ft_calloc(1, 1);
	if (!sol)
		return (NULL);
	bytes_read = 1;
	buffer[0] = 0;
	buffer[1] = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1);
		buffer[bytes_read] = '\0';
		sol = append_n_str(sol, buffer, 1);
		if (!sol)
			return (NULL);
		if (buffer[0] == '\n')
			return (sol);
	}
	return (sol);
}
