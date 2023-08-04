/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isorientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:40:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/04 13:17:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_check_components_range(t_vector vect)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (vect[i] < -1.0 || vect[i] > 1.0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isorientation(char *str, t_vector orient)
{
	double	length;

	if (! ft_isvector(str, orient))
		return (0);
	length = ft_module(orient);
	if (length < 0.25)
		return (ft_log_error(ISORIENTATION_MOD_TOO_LOW));
	if (! ft_check_components_range(orient))
		return (ft_log_error(ISORIENTATION_COMPS_OOR));
	ft_scale_vector(orient, orient, 1 / length);
	return (1);
}
