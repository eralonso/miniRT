/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexistingfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:05:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 10:26:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../../libft/libft.h"
#include "../common.h"

int	ft_isexistingfile(char *str, char **filename)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_log_error(ISNOTEXISTINGFILE));
	close(fd);
	*filename = ft_strdup(str);
	if (!filename)
		ft_log_error(ISNEF_STR_DUPERR);
	return (1);
}
