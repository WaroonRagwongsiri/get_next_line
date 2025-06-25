/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:45:18 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/06/25 20:39:35 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
int		check_empty(char *str);

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
	if (check_empty(sol))
		return (NULL);
	return (sol);
}

int	check_empty(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (1);
	}
	return (0);
}
