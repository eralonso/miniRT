/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cyl_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/13 17:19:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

int inter_cyl_line(t_vector ret, t_line line, void *figure)
{
    // from line = p + t * v
    t_cylinder  *cyl = (t_cylinder *)figure;
	t_vector    w;
    double      radius = cyl->diameter / 2.0;        		// radius
	double      v_dot_h = ft_dot_product(line.orientation, cyl->orientation);

    ft_substraction(w, line.point, cyl->point);
	if (v_dot_h == 1.0)
		return (0); // line and axis paralels

	double  v_dot_w = ft_dot_product(line.orientation, w);
	double  w_dot_h = ft_dot_product(w, cyl->orientation);

	double a_coef = ft_dot_product(line.orientation, line.orientation) - v_dot_h * v_dot_h;
	double b_h_coef = (v_dot_w - v_dot_h * w_dot_h);
	double c_coef = ft_dot_product(w, w) - w_dot_h * w_dot_h - radius * radius;
	double disc = (b_h_coef * b_h_coef - a_coef * c_coef);

    // if denominator=0, no intersect
    if(disc < 0)
        return (0); // return NaN point

	// find the closest distance
	double d = (- b_h_coef - sqrt(disc)) / (a_coef);
    // find cloeset intersection point by substituting d to line eq

    t_vector    line_int;
    ft_addition(line_int, line.point, ft_scale_vector(line_int, line.orientation, d));
    if (ft_dot_product(cyl->orientation, ft_substraction(ret, line_int, cyl->point)))
    {
        ft_scale_vector(ret, line_int, 1.0);
        return (1);
    }
    //find the intersection with caps
    t_plane plane;
    ft_scale_vector(plane.orientation, cyl->orientation, 1.0);
    //or center + height if closer;
    ft_scale_vector(plane.point, cyl->point, 1.0);
    inter_plane_line(line_int, line, figure);
    ft_scale_vector(ret, line_int, 1.0);
    return (1);
}