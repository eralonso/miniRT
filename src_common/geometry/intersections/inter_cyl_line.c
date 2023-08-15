/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cyl_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/15 15:54:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>
#include <stdio.h>

static int	ft_coef_calc(double coef[3], t_line line, const t_cylinder *cyl)
{
	t_vector			w;
	double				radius;
	double				v_dot_h;
	double				v_dot_w;
	double				w_dot_h;

	radius = cyl->diameter / 2.0;
	v_dot_h = ft_dot_product(line.orientation, (double *)cyl->orientation);
	ft_substraction(w, line.point, (double *)cyl->point);

	if (fabs(v_dot_h) > 0.99)
		return (0);
	v_dot_w = ft_dot_product(line.orientation, w);
	w_dot_h = ft_dot_product(w, (double *)cyl->orientation);
	coef[0] = ft_dot_product(line.orientation, line.orientation);
	coef[0] -= v_dot_h * v_dot_h;
	coef[1] = (v_dot_w - v_dot_h * w_dot_h);
	coef[2] = ft_dot_product(w, w) - w_dot_h * w_dot_h - radius * radius;
	return (1);
}

static int	ft_cap_inters(t_intersect_data *ret, \
	t_line line, const t_cylinder *cyl)
{
	t_line				cyl_axis;
	t_intersect_data	cap_center;
	double				sign;
	double				axe_dist;

	return (0);
	ft_copy_vector(ret->tan_plane.orientation, (double *)cyl->orientation);
	sign = -ft_dot_product(line.orientation, (double *)cyl->orientation);
	ft_addition(ret->tan_plane.point, (double *)cyl->point, \
		ft_scale_vector(ret->tan_plane.point, \
			(double *)cyl->orientation, sign * cyl->height / 2.0));
	ret->tan_plane.color = cyl->color;
	if (inter_plane_line(ret, line, (void *)&ret->tan_plane) == 0.0)
		return (0);
	ft_copy_vector(cyl_axis.orientation, (double *)cyl->orientation);
	ft_copy_vector(cyl_axis.point, ret->tan_plane.point);
	inter_plane_line(&cap_center, cyl_axis, (void *)&ret->tan_plane);
	axe_dist = ft_distance_sq(cap_center.tan_plane.point, ret->tan_plane.point);
	return (axe_dist <= (cyl->diameter * cyl->diameter / 4.0));
}

int	inter_cyl_line(t_intersect_data *ret, t_line line, void *figure)
{
	const t_cylinder	*cyl = (t_cylinder *)figure;
	double				coef[3];
	double				int_height;
	t_vector			line_int;

	if (!ft_coef_calc(coef, line, cyl))
		return (ft_cap_inters(ret, line, figure));
	ret->distance = ft_quadrat_eq(coef);
	if (ret->distance == INFINITY)
		return (0);
	ret->tan_plane.color = cyl->color;
	ft_addition(line_int, line.point, \
		ft_scale_vector(line_int, line.orientation, ret->distance));
	int_height = ft_dot_product((double *)cyl->orientation, \
		ft_substraction(ret->tan_plane.point, line_int, (double *)cyl->point));
	if (fabs(int_height) < (cyl->height / 2.0))
	{
		ft_copy_vector(ret->tan_plane.point, line_int);
		return (1);
	}
	if ((int_height * ft_dot_product(line.orientation, \
			(double *)cyl->orientation)) >= 0)
		return (0);
	return (ft_cap_inters(ret, line, figure));
}

// int inter_cyl_line(t_vector ret, t_line line, void *figure)
// {
//     // from line = p + t * v
//     t_cylinder  *cyl = (t_cylinder *)figure;
// 	t_vector    w;
//     double      radius = cyl->diameter / 2.0;        		// radius
// 	double      v_dot_h = ft_dot_product(line.orientation, cyl->orientation);

//     ft_substraction(w, line.point, cyl->point);
// 	if (v_dot_h == 1.0)
// 		return (0); // line and axis paralels

// 	double  v_dot_w = ft_dot_product(line.orientation, w);
// 	double  w_dot_h = ft_dot_product(w, cyl->orientation);

// 	double a_coef = ft_dot_product(line.orientation, line.orientation) - v_dot_h * v_dot_h;
// 	double b_h_coef = (v_dot_w - v_dot_h * w_dot_h);
// 	double c_coef = ft_dot_product(w, w) - w_dot_h * w_dot_h - radius * radius;
// 	double disc = (b_h_coef * b_h_coef - a_coef * c_coef);

//     // if denominator=0, no intersect
//     if(disc < 0)
//         return (0); // return NaN point

// 	// find the closest distance
// 	double d = (- b_h_coef - sqrt(disc)) / (a_coef);
//     // find cloeset intersection point by substituting d to line eq

//     t_vector    line_int;
//     ft_addition(line_int, line.point, ft_scale_vector(line_int, line.orientation, d));
//     if (ft_dot_product(cyl->orientation, ft_substraction(ret, line_int, cyl->point)))
//     {
//         ft_scale_vector(ret, line_int, 1.0);
//         return (1);
//     }
//     //find the intersection with caps
//     t_plane plane;
//     ft_scale_vector(plane.orientation, cyl->orientation, 1.0);
//     //or center + height if closer;
//     ft_scale_vector(plane.point, cyl->point, 1.0);
//     inter_plane_line(line_int, line, figure);
//     ft_scale_vector(ret, line_int, 1.0);
//     return (1);
// }