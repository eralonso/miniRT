/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:05:17 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 15:06:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	ft_dot_product(t_vector a, t_vector b)
{
	int		i;
	double	res;

	i = 0;
	res = 0.0;
	while (i < 3)
	{
		res += (a[i] * b[i]);
		i++;
	}
	return (res);
}
