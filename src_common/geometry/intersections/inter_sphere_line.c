/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/07 11:20:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
// dependency: Vector3, Line, Plane

int inter_sphere_line(t_vector *ret, t_line *line, t_sphere *sphere)
{
    // from line = p + t * v
    t_vector *line_o = line->point;            // (x1, y1, z1)
    t_vector *u = line->orientation; //normalize(); // (Vx, Vy, Vz)

    t_vector *center = sphere->point;          // (a, b, c)
    double radius = sphere->diameter / 2.0;        		// radius

	t_vector rel_origin;
    ft_substraction(rel_origin, line_o, center);

	//double a_coef = u.dot(u); //shold be one id u is unitary
	double b_h_coef = ft_dot_product(u, rel_origin);
	double c_coef = ft_dot_product(rel_origin, rel_origin) - radius * radius;
	//double disc = (b_h_coef * b_h_coef - a_coef * c_coef);
	double disc = (b_h_coef * b_h_coef - c_coef);

    // if denominator=0, no intersect
    if(disc < 0)
        return (0); // return NaN point

	// find the closest distance
	//double d = (- b_h_coef - sqrt(disc)) / (a_coef);
 	double d = (- b_h_coef - sqrt(disc));
    // find cloeset intersection point by substituting d to line eq
    ft_scale_vector(ret, \
        ft_addition(ret, line_o, ft_scale_vector(ret, u, d)), \
        1.0);
    return (1);
}