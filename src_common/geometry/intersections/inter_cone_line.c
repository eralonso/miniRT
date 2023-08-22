/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:37:00 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/22 16:48:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>
#include <stdio.h>

static int	ft_coef_calc(double coef[3], t_line line, const t_cone *cone)
{
	double		cos_theta_sq;
	t_vector	w;
	double		v_dot_h;
	double		v_dot_w;
	double		w_dot_h;

	cos_theta_sq = cos(cone->theta);
	cos_theta_sq *= cos_theta_sq;
	v_dot_h = ft_dot_product(line.orientation, (double *)cone->orientation);
	ft_substraction(w, line.point, (double *)cone->point);
	v_dot_w = ft_dot_product(line.orientation, w);
	w_dot_h = ft_dot_product(w, (double *)cone->orientation);
	coef[0] = v_dot_h * v_dot_h;
	coef[0] -= cos_theta_sq;
	if (fabs(coef[0]) < 1.0e-5)
		return (0);
	coef[1] = v_dot_h * w_dot_h;
	coef[1] -= v_dot_w * cos_theta_sq;
	coef[2] = w_dot_h * w_dot_h;
	coef[2] -= ft_dot_product(w, w) * cos_theta_sq;
	return (1);
}

static int	ft_cap_inters(t_intersect_data *ret, \
	t_line line, const t_cone *cone)
{
	t_vector	cap_center;
	double		sign;
	double		axe_dist;
	double		height;
	double		cap_radius;

	ft_copy_vector(ret->tan_plane.orientation, (double *)cone->orientation);
	sign = ft_dot_product(line.orientation, (double *)cone->orientation);
	sign /= -fabs(sign);
	height = cone->heights[(int)round((sign + 1.0) / 2.0)];
	ft_addition(cap_center, (double *)cone->point, \
		ft_scale_vector(cap_center, (double *)cone->orientation, height));
	cap_radius = height * tan(cone->theta);
	ft_copy_vector(ret->tan_plane.point, cap_center);
	// ret->tan_plane.color = cone->color;
	ret->tan_plane.color.r = 0;
	ret->tan_plane.color.g = 0;
	ret->tan_plane.color.b = 0;
	ret->tan_plane.color.a = 0;
	if (inter_plane_line(ret, line, (void *)&ret->tan_plane) == 0.0)
		return (0);
	axe_dist = ft_distance_sq(cap_center, ret->tan_plane.point);
	return (axe_dist <= (cap_radius * cap_radius));
}

static int	ft_give_inters(t_intersect_data *ret, \
	t_vector line_int, const t_cone *cone, double int_height)
{
	t_vector	center;
	t_vector	int_rel_center;
	double		int_radius;

	int_radius = int_height * tan(cone->theta);
	ft_addition(center, (double *) cone->point, \
		ft_scale_vector(center, (double *) cone->orientation, int_height));
	ft_copy_vector(ret->tan_plane.point, line_int);
	ft_substraction(int_rel_center, line_int, center);
	ft_cross_product(ret->tan_plane.orientation, \
		int_rel_center, (double *)cone->orientation);
	ft_cross_product(ret->tan_plane.orientation, \
		ret->tan_plane.orientation, int_rel_center);
	ft_normalize(ret->tan_plane.orientation, ret->tan_plane.orientation);
	return (1);
}

int	inter_cone_line(t_intersect_data *ret, t_line line, void *figure)
{
	const t_cone	*cone = (t_cone *)figure;
	double			coef[3];
	double			int_height;
	t_vector		line_int;

	if (!ft_coef_calc(coef, line, cone))
		return (ft_cap_inters(ret, line, figure));
	ret->distance = ft_quadrat_eq(coef, -1);
	if (ret->distance == INFINITY || ret->distance < 0)
		return (0);
	ret->tan_plane.color = cone->color;
	ret->kr = cone->reflec_ratio;
	ft_addition(line_int, line.point, \
		ft_scale_vector(line_int, line.orientation, ret->distance));
	int_height = ft_dot_product((double *)cone->orientation, \
		ft_substraction(ret->tan_plane.point, line_int, (double *)cone->point));
	if (int_height > cone->heights[0] && int_height < cone->heights[1])
		return (ft_give_inters(ret, line_int, cone, int_height));
	return (ft_cap_inters(ret, line, cone));
}
