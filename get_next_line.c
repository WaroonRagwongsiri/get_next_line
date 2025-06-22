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
	char	buffer[2];
	char	*sol;
	size_t	bytes_read;
	size_t	index_lf;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sol = ft_calloc(1, 1);
	if (!sol)
		return (NULL);
	bytes_read = 1;
	i = 0;
	buffer[0] = 0;
	buffer[1] = 0;
	while (i < BUFFER_SIZE)
	{
		while (bytes_read > 0)
		{
			index_lf = 0;
			bytes_read = read(fd, buffer, 1);
			buffer[bytes_read] = '\0';
			while (index_lf < bytes_read && buffer[index_lf] != '\n')
				index_lf++;
			sol = append_n_str(sol, buffer, index_lf);
			if (!sol)
				return (NULL);
			if (buffer[index_lf] == '\n')
				return (sol);
		}
		i++;
	}
	return (sol);
}
