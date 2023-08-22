/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istheta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:14:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/22 15:55:07 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

int	ft_istheta(char *str, double *theta)
{
	if (!ft_isdouble(str, theta))
		return (0);
	if (*theta < 0 || *theta > 90)
		return (ft_log_error(ISTHETA_NIR));
	*theta = (*theta * M_PI) / 180;
	return (1);
}
