/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:55:00 by marvin            #+#    #+#             */
/*   Updated: 2025/06/21 12:55:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*sol;
	size_t	bytes_read;

	sol = ft_calloc(1, 1);
	if (!sol || fd < 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		sol = append_char(sol, buffer[0]);
		if (buffer[0] == '\n')
			return (sol);
	}
	return (sol);
}
