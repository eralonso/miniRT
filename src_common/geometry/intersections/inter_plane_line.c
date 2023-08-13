/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/13 14:43:10 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

int inter_plane_line(t_vector *res, t_line *line, void *figure)
{
    // from line = p + t * v
    t_plane     *plane = (t_plane *)figure;
    t_vector    *p = &line->point;            // (x1, y1, z1)
    t_vector    *v = &line->orientation;        // (Vx, Vy, Vz)

    // from plane: ax + by + cz + d = 0
    t_vector *n = &plane->orientation;          // (a, b, c)
    double  d = - ft_dot_product(plane->point, *n); // constant term of plane

    // dot products
    double dot1 = ft_dot_product(*n, *v);             // a*Vx + b*Vy + c*Vz
    double dot2 = ft_dot_product(*n, *p);             // a*x1 + b*y1 + c*z1

    // if denominator=0, no intersect
    if(dot1 == 0)
        return (0);

    // find t = -(a*x1 + b*y1 + c*z1 + d) / (a*Vx + b*Vy + c*Vz)
    double t = -(dot2 + d) / dot1;

    // find intersection point by substituting t to line eq
    ft_addition(*res, *p, ft_scale_vector(*res, *v, t));
    return (1);
}