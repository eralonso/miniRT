/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/15 15:31:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>
// dependency: Vector3, Line, Plane

int	inter_sphere_line(t_intersect_data *ret, t_line line, void *figure)
{
	const t_sphere	*sphere = (t_sphere *)figure;
	const double	radius = sphere->diameter / 2.0;
	t_vector		rel_origin;
	double			coefs[2];
	double			disc;

	ft_substraction(rel_origin, line.point, (double *)sphere->point);
	coefs[0] = ft_dot_product(line.orientation, rel_origin);
	coefs[1] = ft_dot_product(rel_origin, rel_origin) - radius * radius;
	disc = (coefs[0] * coefs[0] - coefs[1]);
	if (disc < 0)
		return (0);
	ret->distance = -coefs[0] - sqrt(disc);
	ret->tan_plane.color = sphere->color;
	ft_addition(ret->tan_plane.point, line.point, \
		ft_scale_vector(ret->tan_plane.point, \
			line.orientation, ret->distance));
	ft_normalize(ret->tan_plane.point, ret->tan_plane.point);
	return (1);
}

// int inter_sphere_line(t_vector ret, t_line line, void *figure)
// {
// 	// from line = p + t * v
// 	const t_sphere	*sphere = (t_sphere *)figure;
// 	const double	radius = sphere->diameter / 2.0;        		// radius
// 	t_vector		rel_origin;

// 	ft_substraction(rel_origin, line.point, sphere->point);
// 	// double a_coef = u.dot(u); //shold be one id u is unitary
// 	double b_h_coef = ft_dot_product(line.orientation, rel_origin);
// 	double c_coef = ft_dot_product(rel_origin, rel_origin) - radius * radius;
// 	//double disc = (b_h_coef * b_h_coef - a_coef * c_coef);
// 	double disc = (b_h_coef * b_h_coef - c_coef);

// 	// if denominator=0, no intersect
// 	if (disc < 0)
// 		return (0); // return NaN point

// 	// find the closest distance
// 	// double d = (- b_h_coef - sqrt(disc)) / (a_coef);
// 	double d = (- b_h_coef - sqrt(disc));
// 	// find cloeset intersection point by substituting d to line eq
// 	ft_scale_vector(ret, ft_addition(ret, line.point, \
// 		ft_scale_vector(ret, line.orientation, d)), 1.0);
// 	return (1);
// }