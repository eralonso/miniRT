/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/25 15:19:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_take_argument(int argc, char const *argv[])
{
	int	len;

	if (argc < 2)
	{
		ft_log_error("You must provide a map file as an argument\n");
		exit (-1);
	}
	if (argc > 2)
	{
		ft_log_error("Too many arguments\n");
		exit (-1);
	}
	len = ft_strlen_x(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 3, ".rt", 3))
	{
		ft_log_error("File extension doesn't match with *.rt\n");
		exit (-1);
	}
	return ((char *)argv[1]);
}
