/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skin_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:54:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/05 15:09:49 by omoreno-         ###   ########.fr       */
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
	double	theta;
	double	phi;

	theta = atan2(point[0], point[1]);
	phi = acos(point[2]);
	uv[0] = 1 - ((theta / (M_PI * 2)) + 0.5);
	uv[1] = 1 - (phi / M_PI);
}

void	ft_cylindrical_map(double *uv, t_vector point, t_vector origin, \
			t_vector orientation)
{
	t_vector	trash;
	t_vector	main_axis;
	t_vector	base[2];
	t_vector	xy;
	double		theta;

	ft_substraction(trash, point, origin);
	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product(orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], orientation, base[0]);
	xy[0] = ft_dot_product(base[0], trash);
	xy[1] = ft_dot_product(base[1], trash);
	uv[1] = ft_dot_product(orientation, trash);
	theta = atan2(xy[0], xy[1]);
	uv[0] = 1 - ((theta / (M_PI * 2)) + 0.5);
}

void	ft_cyl_map(double *uv, t_vector point, const t_cylinder *cyl)
{
	t_vector	trash;
	t_vector	main_axis;
	t_vector	base[2];
	t_vector	xy;
	double		theta;

	ft_substraction(trash, point, (double *)cyl->point);
	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product((double *)cyl->orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], (double *)cyl->orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], (double *)cyl->orientation, base[0]);
	xy[0] = ft_dot_product(base[0], trash);
	xy[1] = ft_dot_product(base[1], trash);
	uv[1] = ft_dot_product((double *)cyl->orientation, trash);
	uv[1] = ft_limit_cyl_height(uv[1], cyl);
	theta = atan2(xy[0], xy[1]);
	uv[0] = 1 - ((theta / (M_PI * 2)) + 0.5);
}

void	ft_cone_map(double *uv, t_vector point, const t_cone *cone)
{
	t_vector	trash;
	t_vector	main_axis;
	t_vector	base[2];
	t_vector	xy;
	double		theta;

	ft_substraction(trash, point, (double *)cone->point);
	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product((double *)cone->orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], (double *)cone->orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], (double *)cone->orientation, base[0]);
	xy[0] = ft_dot_product(base[0], trash);
	xy[1] = ft_dot_product(base[1], trash);
	uv[1] = ft_dot_product((double *)cone->orientation, trash);
	uv[1] = ft_limit_cone_height(uv[1], cone);
	theta = atan2(xy[0], xy[1]);
	uv[0] = 1 - ((theta / (M_PI * 2)) + 0.5);
}
