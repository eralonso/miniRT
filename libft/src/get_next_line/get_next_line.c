/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:22:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/08 12:26:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_x(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

static char	*ft_extract_line_from_buf(char **buffer, size_t	buf_size)
{
	char	*p;
	char	*line;
	size_t	line_size;

	if (! *buffer)
		return (NULL);
	p = ft_strnl(*buffer);
	if (! p)
		return (NULL);
	line_size = p - *buffer + 1;
	line = ft_substr_empty2null(*buffer, 0, line_size, 1);
	if (!line)
		return (NULL);
	p = ft_substr_empty2null(*buffer, line_size, buf_size, 1);
	free_x((void **)buffer);
	*buffer = p;
	return (line);
}

static char	*ft_read_n_extract(int fd, char **buffer, int *read_ret, \
	size_t *buf_size)
{
	char	*new_buf;
	char	chunk[BUFFER_SIZE + 1];
	char	*line;

	if (! buffer || !read_ret)
		return (NULL);
	*read_ret = read(fd, chunk, BUFFER_SIZE);
	if (! *buffer && *read_ret < 1)
		return (NULL);
	new_buf = ft_strjoin_x(*buffer, chunk, buf_size, *read_ret);
	free_x ((void **)buffer);
	*buffer = new_buf;
	if (*read_ret >= 0)
	{
		line = ft_extract_line_from_buf(buffer, *buf_size);
		if (!line && *buffer && *read_ret == 0)
		{
			line = *buffer;
			*buffer = NULL;
		}
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			r_r;
	size_t		buf_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	r_r = read(fd, NULL, 0);
	r_r = r_r >= 0;
	line = NULL;
	buf_size = ft_strlen_x(buf);
	while ((r_r > 0) && !line)
		line = ft_read_n_extract(fd, &buf, &r_r, &buf_size);
	if (line && (r_r < 0 || !line[0]))
		free_x ((void **)&line);
	if (buf && (r_r < 0 || !line))
		free_x ((void **)&buf);
	return (line);
}
