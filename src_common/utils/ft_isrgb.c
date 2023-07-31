/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 12:59:07 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isrgb(char *str, t_rgba *ret)
{
	char			**str_arr;
	unsigned char	ui_arr[3];
	int				i;

	if (!str)
		return (ft_log_error(ISRGB_MISS_STR));
	str_arr = ft_split(str, ',');
	if (!str_arr && ft_matrixlen(str_arr) != 3)
		return (ft_log_error(ISRGB_SIZE));
	i = 0;
	while (i < 3 && ft_isunsignedchar(str_arr[i], &ui_arr[i]))
		i++;
	if (i != 3)
		return (0);
	if (ret)
	{
		ret->a = 0;
		ret->r = ui_arr[0];
		ret->g = ui_arr[1];
		ret->b = ui_arr[2];
	}
	return (1);
}
