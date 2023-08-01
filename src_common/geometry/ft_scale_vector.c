/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:46:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 11:49:35 by omoreno-         ###   ########.fr       */
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
