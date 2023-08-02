/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunsignedchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:52:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/02 12:42:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "utils.h"

int	ft_isunsignedchar(char *str, unsigned char *ret)
{
	int	i;

	if (!str || !str[0])
		return (ft_log_error(ISUNSIGNEDCHAR_MISS_STR));
	if (ft_strlen(str) > 3 || (ft_strlen(str) == 3 
			&& ft_strncmp(str, "255", 3) > 0))
		return (ft_log_error(ISUNSIGNEDCHAR_NIR));
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_log_error(ISUNSIGNEDCHAR_NAN));
	}
	if (ret)
		*ret = (unsigned char)ft_atoi(str);
	return (1);
}
