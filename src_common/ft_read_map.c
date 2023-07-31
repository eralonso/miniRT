/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:28:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/26 12:02:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_list	*ft_read_map_lines(int fd)
{
	char	*line;
	t_list	*list;
	t_list	*new_node;

	line = get_next_line(fd);
	list = NULL;
	while (line)
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(&list, &free);
			ft_log_error("Malloc failed on reading file\n");
			exit (-1);
		}
		ft_lstadd_front(&list, new_node);
		line = get_next_line(fd);
	}
	return (list);
}

t_list	*ft_read_map(char *filename)
{
	int		fd;
	int		cr;
	t_list	*list;

	list = NULL;
	if (! filename)
	{
		ft_log_error("Filename is (NULL)\n");
		exit(-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_log_error("File open failed\n");
		exit(-1);
	}
	list = ft_read_map_lines(fd);
	cr = close(fd);
	return (list);
}
