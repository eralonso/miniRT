/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_class_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:45:15 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/09 16:03:27 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "geometry.h"

// double	**ft_matrix_rotation_round(t_vector axis, double theta)
// {
// 	;
// }

static double	**ft_rotation_around_z_y(double psi, double theta)
{
	double	**rot_z;
	double	**rot_y;
	double	**rot_yz;

	rot_z = ft_matrix_rotation(2, psi);
	rot_y = ft_matrix_rotation(2, theta);
	rot_yz = NULL;
	if (rot_z && rot_y)
		rot_yz = ft_matrix_x_matrix(rot_y, rot_z);
	rot_y = ft_matrix_dispose(rot_y);
	rot_z = ft_matrix_dispose(rot_z);
	return (rot_yz);
}

double	**ft_matrix_align_z(double	*theta, double *psi, t_vector direc)
{
	double	*axis;
	double	*xy_rot_axis;
	double	**rot;

	axis = ft_vector_unitary(2);
	*theta = asin(ft_dot_product(direc, axis));
	if (*theta > -1.0e-3 && *theta < 1.0e-3)
		return (ft_matrix_identity());
	xy_rot_axis = ft_vector_create(axis);
	if (!axis || !xy_rot_axis)
	{
		axis = ft_vector_dispose(axis);
		xy_rot_axis = ft_vector_dispose(xy_rot_axis);
		return (NULL);
	}
	ft_cross_product(xy_rot_axis, direc, axis);
	axis = ft_vector_dispose(axis);
	axis = ft_vector_unitary(1);
	if (!axis)
		return (NULL);
	*psi = asin(ft_dot_product(xy_rot_axis, axis));
	axis = ft_vector_dispose(axis);
	xy_rot_axis = ft_vector_dispose(xy_rot_axis);
	return (ft_rotation_around_z_y(*psi, *theta));
}
