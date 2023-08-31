/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:14:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 14:55:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

int	ft_isangle(char *str, double *alpha)
{
	if (!ft_isdouble(str, alpha))
		return (0);
	if (*alpha < -180 || *alpha > 180)
		return (ft_log_error(ISANGLE_NIR));
	*alpha = (*alpha * M_PI) / 180;
	return (1);
}
