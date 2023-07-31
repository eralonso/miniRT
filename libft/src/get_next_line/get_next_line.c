/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:22:42 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/30 10:40:02 by omoreno-         ###   ########.fr       */
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

static int	ft_get_next_chunk(int fd, char **cnk, size_t cnk_s, size_t buf_s)
{
	t_get_next_chunk	s;

	s.r_r = 1;
	s.tot_r = 0;
	s.nl_pos = NULL;
	if (buf_s > cnk_s)
		cnk_s = buf_s;
	*cnk = (char *)malloc(cnk_s + 1);
	if (! *cnk)
		return (FAIL_MEM_ALLOC_READ_RET);
	while (s.r_r > 0 && cnk_s - s.tot_r >= buf_s && ! s.nl_pos)
	{
		s.r_r = read(fd, *cnk + s.tot_r, buf_s);
		(*cnk)[s.tot_r + buf_s] = 0;
		s.nl_pos = ft_strnl(*cnk + s.tot_r);
		if (s.r_r > 0)
			s.tot_r += s.r_r;
		if (s.r_r < 0 || s.tot_r == 0)
		{
			free_x((void **)cnk);
			s.tot_r = s.r_r;
		}
	}
	return (s.tot_r);
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
	char	*new_chunk;
	char	*line;

	*read_ret = ft_get_next_chunk(fd, &new_chunk, MIN_CHUNK_SIZE, BUFFER_SIZE);
	if (! *buffer && ! new_chunk)
		return (NULL);
	if (new_chunk)
	{
		new_buf = ft_strjoin_x(*buffer, new_chunk, buf_size, *read_ret);
		free_x ((void **)buffer);
		free_x ((void **)&new_chunk);
		*buffer = new_buf;
	}
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
