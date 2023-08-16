/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cyl_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/16 17:37:07 by omoreno-         ###   ########.fr       */
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
	t_vector	cap_center;
	double		sign;
	double		axe_dist;

	ft_copy_vector(ret->tan_plane.orientation, (double *)cyl->orientation);
	sign = -ft_dot_product(line.orientation, (double *)cyl->orientation);
	sign /= fabs(sign);
	ft_addition(cap_center, (double *)cyl->point, \
		ft_scale_vector(cap_center, \
			(double *)cyl->orientation, sign * cyl->height / 2.0));
	ft_copy_vector(ret->tan_plane.point, cap_center);
	ret->tan_plane.color = cyl->color;
	if (inter_plane_line(ret, line, (void *)&ret->tan_plane) == 0.0)
		return (0);
	axe_dist = ft_distance_sq(cap_center, ret->tan_plane.point);
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
	if (ret->distance == INFINITY || ret->distance < 0)
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
