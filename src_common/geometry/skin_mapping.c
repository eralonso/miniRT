/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skin_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:54:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 14:05:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"
#include <math.h>

void	ft_planar_map(double *uv, t_vector point, t_vector origin, \
			t_vector orientation)
{
	t_vector	trash;
	t_vector	main_axis;
	t_vector	base[2];

	ft_substraction(trash, point, origin);
	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product(orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], orientation, base[0]);
	uv[0] = ft_dot_product(base[0], trash);
	uv[1] = ft_dot_product(base[1], trash);
}

void	ft_spherical_map(double *uv, t_vector point)
{
	float	theta;
	float	phi;

	theta = atan2(point[0], point[1]);
	phi = acos(point[2]);
	uv[0] = 1 - ((theta / (M_PI * 2)) + 0.5);
	uv[1] = 1 - (phi / M_PI);
}
