/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/14 11:06:47 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

int inter_plane_line(t_vector res, t_line line, void *figure)
{
	const t_plane	*plane = (t_plane *)figure;
	double			d;
	double			dot1;
	double			dot2;
	double			t;

	d = -ft_dot_product((double *)plane->point, (double *)plane->orientation);
	dot1 = ft_dot_product((double *)plane->orientation, line.orientation);
	dot2 = ft_dot_product((double *)plane->orientation, line.point);
	if (dot1 == 0)
		return (0);
	t = -(dot2 + d) / dot1;
	if (t < 0)
		return (0);
	ft_addition(res, line.point, ft_scale_vector(res, line.orientation, t));
	return (1);
}

// int inter_plane_line(t_vector res, t_line line, void *figure)
// {
//     // from line = p + t * v
//     t_plane     *plane = (t_plane *)figure;

//     // from plane: ax + by + cz + d = 0
//     double  d = - ft_dot_product(plane->point, plane->orientation); // constant term of plane

//     // dot products
//     double dot1 = ft_dot_product(plane->orientation, line.orientation);             // a*Vx + b*Vy + c*Vz
//     double dot2 = ft_dot_product(plane->orientation, line.point);             // a*x1 + b*y1 + c*z1

//     // if denominator=0, no intersect
//     if(dot1 == 0)
//         return (0);

//     // find t = -(a*x1 + b*y1 + c*z1 + d) / (a*Vx + b*Vy + c*Vz)
//     double t = -(dot2 + d) / dot1;

//     // find intersection point by substituting t to line eq
//     ft_addition(res, line.point, ft_scale_vector(res, line.orientation, t));
//     return (1);
// }