/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:46:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/11 11:28:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	*ft_scale_vector(t_vector res, t_vector a, double s)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		res[i] = s * a[i];
		i++ ;
	}
	return (res);
}
