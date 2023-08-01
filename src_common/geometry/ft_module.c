/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_module.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:21:00 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 12:01:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "geometry.h"

double	ft_module(t_vector a)
{
	int		i;
	double	res;

	i = 0;
	res = 0.0;
	while (i < 3)
	{
		res += (a[i] * a[i]);
		i++;
	}
	return (sqrt(res));
}
