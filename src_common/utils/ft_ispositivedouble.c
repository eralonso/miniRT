/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispositivedouble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:29:49 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/22 15:55:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

int	ft_ispositivedouble(char *str, double *value)
{
	if (!ft_isdouble(str, value))
		return (0);
	if (*value < 0)
		return (ft_log_error(ISPOSITIVEDOUBLE_NIR));
	return (1);
}
