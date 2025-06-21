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
	size_t	index_lf;

	index_lf = -1;
	while (++index_lf < BUFFER_SIZE)
		buffer[BUFFER_SIZE] = 0;
	sol = ft_calloc(1, 1);
	if (!sol || fd < 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		index_lf = 0;
		bytes_read = read(fd, buffer, sizeof(buffer));
		while (buffer[index_lf] && buffer[index_lf] != '\n')
			index_lf++;
		sol = append_n_str(sol, buffer, index_lf);
		if (!sol)
			return (NULL);
		if (buffer[index_lf] == '\n')
			return (sol);
	}
	return (sol);
}
