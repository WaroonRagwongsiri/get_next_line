/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:55:06 by marvin            #+#    #+#             */
/*   Updated: 2025/06/21 12:55:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*append_n_str(char *old, char *read, size_t index_lf);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);

#endif