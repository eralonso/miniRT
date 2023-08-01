/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_sq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:57:44 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 12:01:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	ft_distance_sq(t_vector a, t_vector b)
{
	int			i;
	double		res;
	double		comp_dif;

	i = 0;
	res = 0.0;
	while (i < 3)
	{
		comp_dif = b[i] - a[i];
		res += (comp_dif * comp_dif);
		i++;
	}
	return (res);
}
