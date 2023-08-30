/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvector2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:27:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/30 13:29:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isvector2d(char *str, t_vector2d vect)
{
	char	**str_arr;
	double	ui_arr[2];
	int		i;

	if (!str)
		return (ft_log_error(ISVECTOR_MISS_STR));
	str_arr = ft_split(str, ',');
	if (!str_arr || ft_matrixlen(str_arr) != 2)
		return (ft_delete_str_arr(str_arr), ft_log_error(ISVECTOR2D_SIZE));
	i = 0;
	while (i < 2 && ft_isdouble(str_arr[i], &ui_arr[i]))
		i++;
	if (i != 2)
		return (ft_delete_str_arr(str_arr), 0);
	if (vect)
	{
		i = 0;
		while (i < 2)
		{
			vect[i] = ui_arr[i];
			i++;
		}
	}
	ft_delete_str_arr(str_arr);
	return (1);
}
