/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:27:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 16:40:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isvector(char *str, t_vector ret)
{
	char	**str_arr;
	double	ui_arr[3];
	int		i;

	if (!str)
		return (ft_log_error(ISVECTOR_MISS_STR));
	str_arr = ft_split(str, ',');
	if (!str_arr && ft_matrixlen(str_arr) != 3)
		return (ft_log_error(ISVECTOR_SIZE));
	i = 0;
	while (i < 3 && ft_isdouble(str_arr[i], &ui_arr[i]))
		i++;
	if (i != 3)
		return (0);
	if (ret)
	{
		i = 0;
		while (i < 3)
		{
			ret[i] = ui_arr[i];
			i++;
		}
	}
	return (1);
}
