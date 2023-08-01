/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:08:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 15:38:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	*ft_cross_product(t_vector res, t_vector a, t_vector b)
{
	int			i;
	int			j;
	int			k;
	t_vector	aux;

	i = 0;
	while (i < 3)
	{
		j = (i + 1) % 3;
		k = (i - 1) % 3;
		aux[i] = (a[j] * b[k]) - (a[k] * b[j]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		res[i] = aux[i];
		i++;
	}
	return (res);
}
