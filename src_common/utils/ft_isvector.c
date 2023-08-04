/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:27:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/04 12:51:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isvector(char *str, t_vector vect)
{
	char	**str_arr;
	double	ui_arr[3];
	int		i;

	if (!str)
		return (ft_log_error(ISVECTOR_MISS_STR));
	str_arr = ft_split(str, ',');
	if (!str_arr || ft_matrixlen(str_arr) != 3)
		return (ft_delete_str_arr(str_arr), ft_log_error(ISVECTOR_SIZE));
	i = 0;
	while (i < 3 && ft_isdouble(str_arr[i], &ui_arr[i]))
		i++;
	if (i != 3)
		return (ft_delete_str_arr(str_arr), 0);
	if (vect)
	{
		i = 0;
		while (i < 3)
		{
			vect[i] = ui_arr[i];
			i++;
		}
	}
	ft_delete_str_arr(str_arr);
	return (1);
}
