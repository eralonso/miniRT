/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/17 12:49:35 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

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
	ft_substraction(ret->tan_plane.orientation, \
		ret->tan_plane.point, (double *)sphere->point);
	ft_normalize(ret->tan_plane.orientation, ret->tan_plane.orientation);
	return (1);
}
